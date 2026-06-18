# LispCompiler

This takes a little Lisp-looking language and spits out one HTML file that draws animated 3D graphics in a browser. It does not run your code. It reads the source, builds a syntax tree, runs a few optimization passes over that tree, and then walks it to print out JavaScript that calls `glsim.js`, which is a WebGL stand-in for the old fixed-function OpenGL API. The lexer is Flex, the grammar is Bison, and everything around them is C.

The sample program in `input` is a solar system. Planets orbit a sun, the moon orbits earth, a purple cube wanders around on its own orbit for no good reason, and the whole thing animates with `requestAnimationFrame`. The generated page is titled `Planets Go Brrrr!!!11!1`. I never claimed to be good at naming things.

## What it can do

- Turns S-expressions into an AST and compiles that AST straight to JavaScript inside a full HTML document.
- Variables (`define`, `set!`), functions (`defun`), `if`, and a counting `loop`.
- Arithmetic and the boolean operators, both variadic, plus the six comparisons.
- A graphics vocabulary on top of all that: triangles with per-vertex color, lines, spheres, cubes, lighting, `clear`, and `sin`/`cos`.
- Three optimization passes before anything is printed: constant folding, dead-code removal, and unused-variable elimination.
- An escape hatch where any unknown `(name args...)` form is emitted as a raw JS function call, so you can reach `glsim` functions I never bothered to wrap.

## What you need

| Tool | What it's for |
| --- | --- |
| `bison` | builds the parser from `lisp.y` (run with `-d` so it also emits `lisp.tab.h`) |
| `flex` | builds the lexer from `lisp.l` |
| `gcc` | compiles the two generated C files into `a.out` |
| A WebGL browser | actually runs the page. The script assumes `firefox`, but anything modern works. |

One thing to know up front: the page loads `glsim.js` from a CSU Chico URL over the network, so the output needs an internet connection to render unless you point the script tag at a local copy. That tag lives in the `header` string near the top of `lisp.y`, so that is where you would change it.

## Building and running

There is a `project.sh` wrapper for the three steps. From the repo root:

```bash
./project.sh build   # bison -d lisp.y && flex lisp.l && gcc lisp.tab.c lex.yy.c
./project.sh run     # ./a.out < input > output.html
./project.sh test    # firefox output.html
```

`build` generates the parser and lexer and compiles them. `run` pipes the file named `input` into the compiler and dumps the page into `output.html`. `test` opens it. If Firefox is not your thing, open `output.html` in whatever you have.

To compile something other than the demo, edit `input` or just pipe a file in directly:

```bash
./a.out < my_scene.lisp > my_scene.html
```

## The language

It is all S-expressions. Numbers are floats (negatives and bare decimals like `.5` both lex fine), identifiers are normal C-style names, strings are double-quoted, and `;` runs to the end of the line as a comment. There is one small inside joke baked into the lexer: inside a string, `~%` gets rewritten to a JavaScript `\n`, which is Common Lisp's newline directive from `format`. I liked it, so it stayed.

```lisp
; variables
(define x 5)
(set! x (+ x 1))

; functions
(defun square (n) (* n n))
(display (square 4))

; control flow
(if (> x 3) (display "big") (display "small"))
(loop for i from 0 to 10 by 1 do
  (display i))

; arithmetic takes as many args as you want
(+ 1 2 3 4)        ; this one folds to 10 before it's ever printed
(* 2 (sin x))
```

`+`, `-`, `*`, `/`, `and`, and `or` are variadic, so `(+ 1 2 3 4)` is a single node holding a list, not a stack of nested binary ops. The comparisons (`>`, `<`, `>=`, `<=`, `=`) are binary only. `=` compiles to JavaScript `===` rather than `==`, which is almost always what you actually meant.

### Graphics

The graphics forms compile down to `glsim` calls. The 3D shapes take their color by name. The recognized ones are `red`, `green`, `blue`, `yellow`, `cyan`, `magenta`, `white`, `orange`, `purple`, and `lime`, and anything I didn't list falls back to white.

```lisp
; clear to an RGBA color
(clear (0 0 0 1))

; a 2D triangle, color and position given per vertex
(triangle (color 1 0 0 pos -0.5 -0.5)
          (color 0 1 0 pos  0.5 -0.5)
          (color 0 0 1 pos  0.0  0.5))

; sphere/cube: a color name, then rotation, scale, and translation triples
(sphere yellow (0 0 0) (1.5 1.5 1.5) (0 0 0))
(cube purple (0 45 0) (0.75 0.75 0.75) (3 0 0))

; lighting and animation
(light on)
(setlight 0 0 0 1)
(reqanimframe draw)     ; -> requestAnimationFrame(draw)
(setinterval tick 16)   ; -> setInterval(tick, 16)
```

About that escape hatch. If you write `(glBegin GL_LINE_LOOP)` or `(glVertex3f x y z)`, the compiler sees an identifier in call position that it doesn't recognize as a keyword, and just prints it back out as a JavaScript call. That is exactly how the demo's `drawOrbitRing` function draws its orbit rings, calling `glBegin`, `glColor3f`, `glVertex3f`, and `glEnd` by hand. It is a little bit of a cheat, but wrapping every GL function I might ever want would have been a lot of grammar for not much benefit.

## How it works

Short pipeline, one direction: Flex feeds Bison, Bison builds the AST, three passes rewrite the AST, and the pretty printer walks it and prints JavaScript.

Every node is the same `AST` struct. It carries a type tag, a float `value`, an optional `name`, and four child pointers, `first` through `fourth`. Most nodes only need three children. The loop and the two 3D primitives needed a fourth, so there is a second constructor, `make_node_four`, just for those. Argument lists are built as little chains of `NODE_ARGLIST` nodes, sort of like cons cells, which is handy because most of the printing code can walk `->second` until it hits `NULL` and call it a day.

The three passes all run bottom-up over the tree before a single character of output is printed:

1. **Constant folding** (`folding`). Any `+`, `-`, `*`, or `/` whose arguments are all number literals collapses into one number node. So `(+ 1 2 3 4)` in the source turns into `console.log(10)` in the output instead of `console.log(1 + 2 + 3 + 4)`.
2. **Dead-code removal** (`dead_code_removal`). A top-level expression that is just a bare value with no side effect, like a lone `(+ 5 5)`, gets dropped. Computing a number and then throwing it away accomplishes nothing, so out it goes.
3. **Unused-variable elimination** (`remove_unused_assignments`). A `define` or `set!` whose name never appears anywhere else gets cut. The usage test, `is_used`, just searches the whole tree for a matching `ID` node. That is conservative and not scope-aware, so all it can really tell you is that a name shows up somewhere, but for a single-file toy language that is good enough.

The demo file leans on all three on purpose so you can see them work. `(+ 1 2 3 4)` folds to `10`, the bare `(+ 5 5)` vanishes, and `(define uselessVariable 21)` is stripped out because nothing ever reads it.

Codegen itself is one big `switch` in `pretty()` that prints JS to stdout. Sequences print their children and terminate statements with `;`, `defun` becomes a `function`, `loop` becomes a `for`, `if` becomes `if`/`else`, and the graphics nodes expand into their `gl*` calls. The sphere and cube cases do the most work: each emits `glPushMatrix`, a translate, three axis rotations, a scale, the color, the geometry call, and finally `glPopMatrix`, in that order, so the transforms stack up the way you would expect. `main()` prints the HTML header, parses, runs the passes, walks the tree, frees it, and prints the footer.

## Known issues

- The unused-variable pass is a flat name search, no concept of scope. Shadowing or a name that appears but isn't actually live could fool it. Fine here, not something I would point at a real codebase.
- The graphics grammar is picky about arity. A `sphere` or `cube` wants exactly three parenthesized triples in a set order, and `triangle` wants exactly three vertex forms. Miss the count and you get a Bison parse error instead of anything friendly.
- No type checking, and error recovery is basically just whatever `yyerror` prints.
- The output depends on a `glsim.js` hosted at a CSU Chico URL. If that ever moves, the generated pages stop rendering until you swap in your own copy.
- `main()` calls `printf(header)` and `printf(footer)` with the strings as the format argument. They contain no stray `%` today so it works, but `printf("%s", header)` is the version that won't blow up the day someone adds a percent sign to that template. I know. It is on the list.

## Credits

Written by Christopher Gemperle for a graphics course at CSU Chico. The grammar and lexer are mine. `glsim.js` is the course-provided OpenGL shim that the output pages depend on.
