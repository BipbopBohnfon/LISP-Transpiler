
%define parse.error detailed

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE_NUMBER 0
#define NODE_SEQ    1
#define NODE_FOR    2
#define NODE_ID     3
#define NODE_STRING 4
#define NODE_ASSIGN 5
#define NODE_DEFINE 6
#define NODE_SET    7
#define NODE_ADD    8
#define NODE_SUBTRACT   9
#define NODE_MULTIPLY   10
#define NODE_DIVIDE 11
#define NODE_GREATER_THAN   12
#define NODE_LESS_THAN  13
#define NODE_GREATER_EQUAL  14
#define NODE_LESS_EQUAL 15
#define NODE_EQUAL  16
#define NODE_AND    17
#define NODE_ARGLIST    18
#define NODE_OR     19
#define NODE_NOT    20
#define NODE_IF     21
#define NODE_LOOP   22
#define NODE_DEFUN  23
#define NODE_CALL   24
#define NODE_DISPLAY    25
#define NODE_NEWLINE    26
#define NODE_CLEAR  28
#define NODE_COLOR  29
#define NODE_TRIANGLE   30
#define NODE_VERTEX 31
#define NODE_REQ_ANIM_FRAME 32
#define NODE_SET_INTERVAL   33
#define NODE_LINES          34
#define NODE_CUBE           35
#define NODE_SPHERE         36
#define NODE_LIGHT          37
#define NODE_SET_LIGHT       38
#define NODE_SIN            39
#define NODE_COS            40

char* header = "<!DOCTYPE html>\n<html>\n<head>\n\
  <title>Planets Go Brrrr!!!11!1</title>\n\
  <style>\n\
    body { background: DarkSlateGrey; display: flex; flex-direction: column;\n\
           align-items: center; justify-content: center;}\n\
    canvas { border: 2px solid; display: block; }\n\
  </style>\n\
  <script src=\"https://www.ecst.csuchico.edu/~oal-saadi/Graphics/source/glsim.js\"></script>\n\
</head>\n\
<body>\n\
  <h1>Planets Go Brrrr!!!11!1</h1>\n\
  <p>Sorry. I'm not very creative.</p>\n\
  <canvas id=\"glcanvas\" width=\"600\" height=\"600\">\n\
  <script>\n\
  glsimUse(\"glcanvas\");\n\
  glMatrixMode(GL_PROJECTION);\n\
  glLoadIdentity();\n\
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);\n\
  glMatrixMode(GL_MODELVIEW);\n\
  glEnable(GL_DEPTH_TEST);\n\
  glLightfv(GL_LIGHT0, GL_AMBIENT, [0.15, 0.15, 0.4, 1.0]);\n\
  function smoothSphere(radius, slices, stacks) {\n\
      var i,j;\n\
      for (j = 0; j < stacks; j++) {\n\
          var latitude1 = (Math.PI/stacks) * j - Math.PI/2;\n\
          var latitude2 = (Math.PI/stacks) * (j+1) - Math.PI/2;\n\
          var sinLat1 = Math.sin(latitude1);\n\
          var cosLat1 = Math.cos(latitude1);\n\
          var sinLat2 = Math.sin(latitude2);\n\
          var cosLat2 = Math.cos(latitude2);\n\
          glBegin(GL_QUAD_STRIP);\n\
          for (i = 0; i <= slices; i++) {\n\
              var longitude = (2*Math.PI/slices) * i;\n\
              var sinLong = Math.sin(longitude);\n\
              var cosLong = Math.cos(longitude);\n\
              var x1 = cosLong * cosLat1;\n\
              var y1 = sinLong * cosLat1;\n\
              var z1 = sinLat1;\n\
              var x2 = cosLong * cosLat2;\n\
              var y2 = sinLong * cosLat2;\n\
              var z2 = sinLat2;\n\
              glNormal3d(x2,y2,z2);\n\
              glVertex3d(radius*x2,radius*y2,radius*z2);\n\
              glNormal3d(x1,y1,z1);\n\
              glVertex3d(radius*x1,radius*y1,radius*z1);\n\
          }\n\
          glEnd();\n\
      }\n\
  }\n\
  function drawCube() {\n\
      glBegin(GL_QUADS);\n\
      // Front face (z+)\n\
      glNormal3d(0, 0, 1);\n\
      glVertex3f(-1, -1,  1); glVertex3f( 1, -1,  1); \n\
      glVertex3f( 1,  1,  1); glVertex3f(-1,  1,  1);\n\
      // Back face (z-)\n\
      glNormal3d(0, 0, -1);\n\
      glVertex3f(-1, -1, -1); glVertex3f(-1,  1, -1); \n\
      glVertex3f( 1,  1, -1); glVertex3f( 1, -1, -1);\n\
      // Top face (y+)\n\
      glNormal3d(0, 1, 0);\n\
      glVertex3f(-1,  1, -1); glVertex3f(-1,  1,  1); \n\
      glVertex3f( 1,  1,  1); glVertex3f( 1,  1, -1);\n\
      // Bottom face (y-)\n\
      glNormal3d(0, -1, 0);\n\
      glVertex3f(-1, -1, -1); glVertex3f( 1, -1, -1); \n\
      glVertex3f( 1, -1,  1); glVertex3f(-1, -1,  1);\n\
      // Right face (x+)\n\
      glNormal3d(1, 0, 0);\n\
      glVertex3f( 1, -1, -1); glVertex3f( 1,  1, -1); \n\
      glVertex3f( 1,  1,  1); glVertex3f( 1, -1,  1);\n\
      // Left face (x-)\n\
      glNormal3d(-1, 0, 0);\n\
      glVertex3f(-1, -1, -1); glVertex3f(-1, -1,  1); \n\
      glVertex3f(-1,  1,  1); glVertex3f(-1,  1, -1);\n\
      glEnd();\n\
  }\n";

char* footer = "</script>\n\
</body>\n\
</html>\n";

typedef struct AST {
    int type;
    float value;
    char* name;
    struct AST* first;
    struct AST* second;
    struct AST* third;
    struct AST* fourth;
} AST;

static void pretty(AST* n);

static void free_ast(AST* n) {
    if (!n) return;
    free_ast(n->first);
    free_ast(n->second);
    free_ast(n->third);
    free_ast(n->fourth);
    if (n->name) free(n->name);
    free(n);
}

static AST* make_node(int type, float value, char* name, AST* first, AST* second, AST* third) {
    AST* n = (AST*)malloc(sizeof(AST));
    n->type = type;
    n->value = value;
    n->name = name;
    n->first = first;
    n->second = second;
    n->third = third;
    n->fourth = NULL;
    return n;
}

static AST* make_arglist(AST* head, AST* tail) {
    return make_node(NODE_ARGLIST, 0, NULL, head, tail, NULL);
}

static AST* make_node_four(int type, float value, char* name, AST* first, AST* second, AST* third, AST* fourth) {
    AST* n = (AST*)malloc(sizeof(AST));
    n->type = type;
    n->value = value;
    n->name = name;
    n->first = first;
    n->second = second;
    n->third = third;
    n->fourth = fourth;
    return n;
}

static void unroll_list(AST* n, const char* delimiter) {
    if (!n) return;
    pretty(n->first);
    if (n->second) {
        printf("%s", delimiter);
        unroll_list(n->second, delimiter);
    }
}

static void print_vertex(AST* v) {
    printf("    glColor3f(");
    pretty(v->first->first);
    printf(", ");
    pretty(v->first->second->first);
    printf(", ");
    pretty(v->first->second->second->first);
    printf(");\n");
    printf("    glVertex2f(");
    pretty(v->second->first);
    printf(", ");
    pretty(v->second->second->first);
    printf(");\n");
}

static void color(const char* name) {
    if      (strcmp(name, "red")     == 0) printf("glColor3f(1.0, 0.0, 0.0);\n");
    else if (strcmp(name, "green")   == 0) printf("glColor3f(0.0, 0.5, 0.0);\n");
    else if (strcmp(name, "blue")    == 0) printf("glColor3f(0.0, 0.0, 1.0);\n");
    else if (strcmp(name, "yellow")  == 0) printf("glColor3f(1.0, 1.0, 0.0);\n");
    else if (strcmp(name, "cyan")    == 0) printf("glColor3f(0.0, 1.0, 1.0);\n");
    else if (strcmp(name, "magenta") == 0) printf("glColor3f(1.0, 0.0, 1.0);\n");
    else if (strcmp(name, "white")   == 0) printf("glColor3f(1.0, 1.0, 1.0);\n");
    else if (strcmp(name, "orange")  == 0) printf("glColor3f(1.0, 0.5, 0.0);\n");
    else if (strcmp(name, "purple")  == 0) printf("glColor3f(0.5, 0.0, 0.5);\n");
    else if (strcmp(name, "lime")    == 0) printf("glColor3f(0.0, 1.0, 0.0);\n");
    else                                   printf("glColor3f(1.0, 1.0, 1.0);\n");
}

static void pretty(AST* n) {
    if (!n) return;
    switch (n->type) {

        case NODE_NUMBER:
            printf("%g", n->value);
            break;

        case NODE_ID:
            printf("%s", n->name);
            break;

        case NODE_STRING:
            printf("%s", n->name);
            break;

        case NODE_SEQ:
            pretty(n->first);
            pretty(n->second);
            printf(";\n");
            break;

        case NODE_DEFINE:
            printf("let %s", n->name);
            if (n->first) { printf(" = "); pretty(n->first); }
            break;

        case NODE_SET:
            printf("%s = ", n->name);
            pretty(n->first);
            break;

        case NODE_DEFUN:
            printf("function %s(", n->name);
            unroll_list(n->first, ", ");
            printf(") {\n");
            for (AST* s = n->second; s; s = s->second) {
                pretty(s->first);
                printf(";\n");
            }
            printf("}");
            break;

        case NODE_IF:
            printf("if (");
            pretty(n->first);
            printf(") {\n");
            pretty(n->second);
            printf(";\n}");
            if (n->third) {
                printf(" else {\n");
                pretty(n->third);
                printf(";\n}");
            }
            break;

        case NODE_LOOP:
            printf("for (let %s = ", n->name);
            pretty(n->first);
            printf("; %s <= ", n->name);
            pretty(n->second);
            printf("; %s += ", n->name);
            pretty(n->third);
            printf(") {\n");
            for (AST* s = n->fourth; s; s = s->second) {
                pretty(s->first);
                printf(";\n");
            }
            printf("}");
            break;

        case NODE_ADD:
            printf("(");
            unroll_list(n->first, " + ");
            printf(")");
            break;

        case NODE_SUBTRACT:
            printf("(");
            unroll_list(n->first, " - ");
            printf(")");
            break;

        case NODE_MULTIPLY:
            printf("(");
            unroll_list(n->first, " * ");
            printf(")");
            break;

        case NODE_DIVIDE:
            printf("(");
            unroll_list(n->first, " / ");
            printf(")");
            break;

        case NODE_GREATER_THAN:
            printf("(");
            pretty(n->first); printf(" > ");
            pretty(n->second); printf(")");
            break;

        case NODE_LESS_THAN:
            printf("(");
            pretty(n->first); printf(" < ");
            pretty(n->second); printf(")");
            break;

        case NODE_GREATER_EQUAL:
            printf("(");
            pretty(n->first); printf(" >= ");
            pretty(n->second); printf(")");
            break;

        case NODE_LESS_EQUAL:
            printf("(");
            pretty(n->first); printf(" <= ");
            pretty(n->second); printf(")");
            break;

        case NODE_EQUAL:
            printf("(");
            pretty(n->first); printf(" === ");
            pretty(n->second); printf(")");
            break;

        case NODE_AND:
            printf("(");
            unroll_list(n->first, " && ");
            printf(")");
            break;

        case NODE_OR:
            printf("(");
            unroll_list(n->first, " || ");
            printf(")");
            break;

        case NODE_NOT:
            printf("(!");
            pretty(n->first);
            printf(")");
            break;

        case NODE_DISPLAY:
            printf("console.log(");
            pretty(n->first);
            printf(")");
            break;

        case NODE_NEWLINE:
            printf("console.log(\"\")");
            break;

        case NODE_CALL:
            printf("%s(", n->name);
            unroll_list(n->first, ", ");
            printf(")");
            break;

        case NODE_CLEAR:
            printf("glClearColor(");
            unroll_list(n->first, ", ");
            printf(");\n");
            printf("glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)");
            break;

        case NODE_TRIANGLE:
            printf("glBegin(GL_TRIANGLES);\n");
            print_vertex(n->first->first);
            print_vertex(n->first->second->first);
            print_vertex(n->first->second->second->first);
            printf("glEnd();");
            break;
        case NODE_REQ_ANIM_FRAME:
            printf("requestAnimationFrame(%s)", n->name);
            break;
        case NODE_SET_INTERVAL:
            printf("setInterval(%s, ", n->name);
            pretty(n->first);
            printf(")");
            break;
        case NODE_SPHERE:
            printf("glPushMatrix();\n");
            printf("glTranslatef(");
            pretty(n->third->first); printf(", ");
            pretty(n->third->second->first); printf(", ");
            pretty(n->third->second->second->first);
            printf(");\n");

            printf("glRotatef("); pretty(n->first->first); printf(", 1, 0, 0);\n");
            printf("glRotatef("); pretty(n->first->second->first); printf(", 0, 1, 0);\n");
            printf("glRotatef("); pretty(n->first->second->second->first); printf(", 0, 0, 1);\n");

            printf("glScalef(");
            pretty(n->second->first); printf(", ");
            pretty(n->second->second->first); printf(", ");
            pretty(n->second->second->second->first);
            printf(");\n");

            color(n->name);
            printf("smoothSphere(1.0, 15, 15);\n");
            printf("glPopMatrix();\n");
            break;
        case NODE_CUBE:
            printf("glPushMatrix();\n");
            printf("glTranslatef(");
            pretty(n->third->first); printf(", ");
            pretty(n->third->second->first); printf(", ");
            pretty(n->third->second->second->first);
            printf(");\n");

            printf("glRotatef("); pretty(n->first->first); printf(", 1, 0, 0);\n");
            printf("glRotatef("); pretty(n->first->second->first); printf(", 0, 1, 0);\n");
            printf("glRotatef("); pretty(n->first->second->second->first); printf(", 0, 0, 1);\n");

            printf("glScalef(");
            pretty(n->second->first); printf(", ");
            pretty(n->second->second->first); printf(", ");
            pretty(n->second->second->second->first);
            printf(");\n");

            color(n->name);
            printf("drawCube();\n");
            printf("glPopMatrix();\n");
            break;

        case NODE_LINES:
            printf("glBegin(GL_LINES);\n");
            color(n->name);
            for (AST* arg = n->first; arg != NULL; arg = arg->second) {
                printf("glVertex3f(");
                pretty(arg->first->first); printf(", ");
                pretty(arg->first->second->first); printf(", ");
                pretty(arg->first->second->second->first);
                printf(");\n");
            }
            printf("glEnd();\n");
            break;

        case NODE_LIGHT:
            if (n->name && strcmp(n->name, "off") == 0) {
                printf("glDisable(GL_LIGHTING);\n");
            } else {
                printf("glEnable(GL_LIGHTING);\n");
                printf("glEnable(GL_LIGHT0);\n");
                printf("glEnable(GL_COLOR_MATERIAL);\n");
            }
            break;

        case NODE_SET_LIGHT:
            printf("glLightfv(GL_LIGHT0, GL_POSITION, [");
            unroll_list(n->first, ", ");
            printf("]);\n");
            break;

        case NODE_SIN:
            printf("Math.sin(");
            pretty(n->first);
            printf(")");
            break;

        case NODE_COS:
            printf("Math.cos(");
            pretty(n->first);
            printf(")");
            break;
        default:
            fprintf(stderr, "/* unknown node type %d */", n->type);
            break;
    }
}

int count_ast(AST* n) {
    if (!n) return 0;
    return 1 + count_ast(n->first) + count_ast(n->second) + count_ast(n->third) + count_ast(n->fourth);
}

int yylex(void);
void yyerror(const char* s);
static AST* root = NULL;
%}

%code requires {
    typedef struct AST AST;
}

%union {
    float f;
    char* s;
    AST* node;
}

%left '+' '-' '='

%token FOR IF THEN ELSE SET DEFINE DEFUN LOOP FROM TO BY DO AND OR NOT DISPLAY NEWLINE CLEAR TRIANGLE COLOR POS GREATER_EQ LESS_EQ REQ_ANIM_FRAME SET_INTERVAL LINES CUBE SPHERE LIGHT SET_LIGHT SIN COS
%token <f> NUMBER
%token <s> STRING ID
%type  <node> expr expr_list input seq vertex arg_list param_list

%%

input
    : seq         { root = $1; $$ = $1; }
    ;

seq
    : seq expr  { $$ = make_node(NODE_SEQ, 0, NULL, $1, $2, NULL); }
    |           { $$ = NULL; }
    ;

expr
    : NUMBER                    { $$ = make_node(NODE_NUMBER, $1, NULL, NULL, NULL, NULL); }
    | ID                        { $$ = make_node(NODE_ID, 0, $1, NULL, NULL, NULL); }
    | STRING                    { $$ = make_node(NODE_STRING, 0, $1, NULL, NULL, NULL); }
    | '(' DEFINE ID expr ')'    { $$ = make_node(NODE_DEFINE, 0, $3, $4, NULL, NULL); }
    | '(' DEFINE ID ')'    { $$ = make_node(NODE_DEFINE, 0, $3, NULL, NULL, NULL); }
    | '(' SET ID expr ')'   { $$ = make_node(NODE_SET, 0, $3, $4, NULL, NULL); }
    | '(' DEFUN ID '(' param_list ')' expr_list ')'   { $$ = make_node(NODE_DEFUN, 0, $3, $5, $7, NULL); }
    | '(' IF expr expr expr ')'   { $$ = make_node(NODE_IF, 0, NULL, $3, $4, $5); }
    | '(' IF expr expr ')'   { $$ = make_node(NODE_IF, 0, NULL, $3, $4, NULL); }
    | '(' LOOP FOR ID FROM expr TO expr BY expr DO expr_list ')'   { $$ = make_node_four(NODE_LOOP, 0, $4, $6, $8, $10, $12); }
    | '(' DISPLAY expr ')'   { $$ = make_node(NODE_DISPLAY, 0, NULL, $3, NULL, NULL); }
    | '(' NEWLINE ')'   { $$ = make_node(NODE_NEWLINE, 0, NULL, NULL, NULL, NULL); }
    | '(' '+' expr_list  ')'  { $$ = make_node(NODE_ADD, 0, NULL, $3, NULL, NULL); }
    | '(' '-' expr_list ')'  { $$ = make_node(NODE_SUBTRACT, 0, NULL, $3, NULL, NULL); }
    | '(' '*' expr_list  ')'  { $$ = make_node(NODE_MULTIPLY, 0, NULL, $3, NULL, NULL); }
    | '(' '/' expr_list ')'  { $$ = make_node(NODE_DIVIDE, 0, NULL, $3, NULL, NULL); }
    | '(' '>' expr expr ')'  { $$ = make_node(NODE_GREATER_THAN,  0, NULL, $3, $4, NULL); }
    | '(' '<' expr expr ')'  { $$ = make_node(NODE_LESS_THAN,  0, NULL, $3, $4, NULL); }
    | '(' GREATER_EQ expr expr ')'  { $$ = make_node(NODE_GREATER_EQUAL, 0, NULL, $3, $4, NULL); }
    | '(' LESS_EQ expr expr ')'  { $$ = make_node(NODE_LESS_EQUAL, 0, NULL, $3, $4, NULL); }
    | '(' '=' expr expr ')'  { $$ = make_node(NODE_EQUAL,  0, NULL, $3, $4, NULL); }
    | '(' AND arg_list ')'   { $$ = make_node(NODE_AND, 0, NULL, $3, NULL, NULL); }
    | '(' OR  arg_list ')'   { $$ = make_node(NODE_OR,  0, NULL, $3, NULL, NULL); }
    | '(' NOT expr     ')'   { $$ = make_node(NODE_NOT, 0, NULL, $3, NULL, NULL); }
    | '(' CLEAR '(' arg_list ')' ')' { $$ = make_node(NODE_CLEAR, 0, NULL, $4, NULL, NULL); }
    | '(' TRIANGLE vertex vertex vertex ')'
        {
            AST* vl = make_arglist($3, make_arglist($4, make_arglist($5, NULL)));
            $$ = make_node(NODE_TRIANGLE, 0, NULL, vl, NULL, NULL);
        }
    /* Function Call */
    | '(' ID arg_list ')' { $$ = make_node(NODE_CALL, 0, $2, $3, NULL, NULL); }
    | '(' REQ_ANIM_FRAME ID ')' { $$ = make_node(NODE_REQ_ANIM_FRAME, 0, $3, NULL, NULL, NULL); }
    | '(' SET_INTERVAL ID expr ')' { $$ = make_node(NODE_SET_INTERVAL, 0, $3, $4, NULL, NULL); }
    | '(' CUBE ID '(' arg_list ')' '(' arg_list ')' '(' arg_list ')' ')' { $$ = make_node_four(NODE_CUBE, 0, $3, $5, $8, $11, NULL); }
    | '(' SPHERE ID '(' arg_list ')' '(' arg_list ')' '(' arg_list ')' ')' { $$ = make_node_four(NODE_SPHERE, 0, $3, $5, $8, $11, NULL); }
    | '(' LINES ID arg_list ')' { $$ = make_node(NODE_LINES, 0, $3, $4, NULL, NULL); }
    | '(' SIN expr ')' { $$ = make_node(NODE_SIN, 0, NULL, $3, NULL, NULL); }
    | '(' COS expr ')' { $$ = make_node(NODE_COS, 0, NULL, $3, NULL, NULL); }
    | '(' LIGHT ID ')' { $$ = make_node(NODE_LIGHT, 0, $3, NULL, NULL, NULL); }
    | '(' SET_LIGHT arg_list ')' { $$ =  make_node(NODE_SET_LIGHT, 0, NULL, $3, NULL, NULL); }
    ;

vertex
    : '(' COLOR expr expr expr POS expr expr ')'
        {
            AST* rgb = make_arglist($3, make_arglist($4, make_arglist($5, NULL)));
            AST* xy  = make_arglist($7, make_arglist($8, NULL));
            $$ = make_node(NODE_VERTEX, 0, NULL, rgb, xy, NULL);
        }
    ;

expr_list
    : expr             { $$ = make_arglist($1, NULL); }
    | expr expr_list   { $$ = make_arglist($1, $2);   }
    ;

arg_list
    :                { $$ = NULL; }
    | expr arg_list  { $$ = make_arglist($1, $2); }
    ;

param_list
    :                   { $$ = NULL; }
    | ID param_list     { $$ = make_arglist(make_node(NODE_ID, 0, $1, NULL, NULL, NULL), $2); }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "parse error: %s\n", s);
}

// Return 1 at end of list if constants, else 0
int all_numbers(AST* args) {
    if (!args) return 1;
    if (args->first->type != NODE_NUMBER) return 0;
    return all_numbers(args->second);
}

float evaluate_constants(int type, AST* args) {
    if (!args) return 0;
    float result = args->first->value;
    args = args->second;

    while (args) {
        if (type == NODE_ADD) result += args->first->value;
        else if (type == NODE_SUBTRACT) result -= args->first->value;
        else if (type == NODE_MULTIPLY) result *= args->first->value;
        else if (type == NODE_DIVIDE) result /= args->first->value;
        args = args->second;
    }
    return result;
}

AST* folding(AST* n) {
    if (!n) return NULL;
    // bottom up
    n->first = folding(n->first);
    n->second = folding(n->second);
    n->third = folding(n->third);
    n->fourth = folding(n->fourth);

    if (n->type == NODE_ADD || n->type == NODE_SUBTRACT ||
        n->type == NODE_MULTIPLY || n->type == NODE_DIVIDE) {
        if (n->first && all_numbers(n->first)) {
            float val = evaluate_constants(n->type, n->first);
            free_ast(n->first);
            n->type = NODE_NUMBER;
            n->value = val;
            n->first = NULL;
        }
    }
    return n;
}

AST* dead_code_removal(AST* n) {
    if (!n) return NULL;
    // bottom up
    n->first = dead_code_removal(n->first);
    n->second = dead_code_removal(n->second);
    n->third = dead_code_removal(n->third);
    n->fourth = dead_code_removal(n->fourth);

    if (n->type == NODE_SEQ) {
        if (n->second && (n->second->type == NODE_NUMBER || n->second->type == NODE_ID)) {
            // Don't remove left child
            AST* keep = n->first;
            free_ast(n->second);
            free(n);
            // reparent
            return keep;
        }
    }
    return n;
}

int is_used(AST* n, char* name) {
    if (!n) return 0;
    // Node used beyond assignment and definition - does not guaruntee is used for final result, but good enough
    if (n->type == NODE_ID && strcmp(n->name, name) == 0) return 1;
    return is_used(n->first, name) || is_used(n->second, name) ||
           is_used(n->third, name) || is_used(n->fourth, name);
}

AST* remove_unused_assignments(AST* n) {
    if (!n) return NULL;

    // bottom up
    n->first = remove_unused_assignments(n->first);
    n->second = remove_unused_assignments(n->second);
    n->third = remove_unused_assignments(n->third);
    n->fourth = remove_unused_assignments(n->fourth);

    // Fold unused node
    if (n->type == NODE_SEQ && n->second == NULL) {
        AST* keep = n->first;
        free(n);
        return keep;
    }

    if (n->type == NODE_DEFINE || n->type == NODE_SET) {
        // Search recursively for usage
        if (!is_used(root, n->name)) {
            free_ast(n->first);
            free(n->name);
            free(n);
            return NULL;
        }
    }
    return n;
}

int main(void) {
    printf(header);
    yyparse();
    root = folding(root);
    root = dead_code_removal(root);
    root = remove_unused_assignments(root);
    pretty(root);
    free_ast(root);
    printf("\n");
    printf(footer);
    return 0;
}
