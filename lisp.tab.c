/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "lisp.y"

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

#line 569 "lisp.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "lisp.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '+'  */
  YYSYMBOL_4_ = 4,                         /* '-'  */
  YYSYMBOL_5_ = 5,                         /* '='  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_THEN = 8,                       /* THEN  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_SET = 10,                       /* SET  */
  YYSYMBOL_DEFINE = 11,                    /* DEFINE  */
  YYSYMBOL_DEFUN = 12,                     /* DEFUN  */
  YYSYMBOL_LOOP = 13,                      /* LOOP  */
  YYSYMBOL_FROM = 14,                      /* FROM  */
  YYSYMBOL_TO = 15,                        /* TO  */
  YYSYMBOL_BY = 16,                        /* BY  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_NOT = 20,                       /* NOT  */
  YYSYMBOL_DISPLAY = 21,                   /* DISPLAY  */
  YYSYMBOL_NEWLINE = 22,                   /* NEWLINE  */
  YYSYMBOL_CLEAR = 23,                     /* CLEAR  */
  YYSYMBOL_TRIANGLE = 24,                  /* TRIANGLE  */
  YYSYMBOL_COLOR = 25,                     /* COLOR  */
  YYSYMBOL_POS = 26,                       /* POS  */
  YYSYMBOL_GREATER_EQ = 27,                /* GREATER_EQ  */
  YYSYMBOL_LESS_EQ = 28,                   /* LESS_EQ  */
  YYSYMBOL_REQ_ANIM_FRAME = 29,            /* REQ_ANIM_FRAME  */
  YYSYMBOL_SET_INTERVAL = 30,              /* SET_INTERVAL  */
  YYSYMBOL_LINES = 31,                     /* LINES  */
  YYSYMBOL_CUBE = 32,                      /* CUBE  */
  YYSYMBOL_SPHERE = 33,                    /* SPHERE  */
  YYSYMBOL_LIGHT = 34,                     /* LIGHT  */
  YYSYMBOL_SET_LIGHT = 35,                 /* SET_LIGHT  */
  YYSYMBOL_SIN = 36,                       /* SIN  */
  YYSYMBOL_COS = 37,                       /* COS  */
  YYSYMBOL_NUMBER = 38,                    /* NUMBER  */
  YYSYMBOL_STRING = 39,                    /* STRING  */
  YYSYMBOL_ID = 40,                        /* ID  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_46_ = 46,                       /* '<'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_input = 48,                     /* input  */
  YYSYMBOL_seq = 49,                       /* seq  */
  YYSYMBOL_expr = 50,                      /* expr  */
  YYSYMBOL_vertex = 51,                    /* vertex  */
  YYSYMBOL_expr_list = 52,                 /* expr_list  */
  YYSYMBOL_arg_list = 53,                  /* arg_list  */
  YYSYMBOL_param_list = 54                 /* param_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    43,     3,     2,     4,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,     5,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   522,   522,   526,   527,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   575,   584,   585,   589,   590,   594,   595
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "'+'", "'-'", "'='", "FOR",
  "IF", "THEN", "ELSE", "SET", "DEFINE", "DEFUN", "LOOP", "FROM", "TO",
  "BY", "DO", "AND", "OR", "NOT", "DISPLAY", "NEWLINE", "CLEAR",
  "TRIANGLE", "COLOR", "POS", "GREATER_EQ", "LESS_EQ", "REQ_ANIM_FRAME",
  "SET_INTERVAL", "LINES", "CUBE", "SPHERE", "LIGHT", "SET_LIGHT", "SIN",
  "COS", "NUMBER", "STRING", "ID", "'('", "')'", "'*'", "'/'", "'>'",
  "'<'", "$accept", "input", "seq", "expr", "vertex", "expr_list",
  "arg_list", "param_list", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -53,     1,     9,   -53,   -53,   -53,   -53,   166,   -53,     9,
       9,     9,     9,   -38,   -36,   -34,    10,     9,     9,     9,
       9,   -23,   -21,   -20,     9,     9,     0,     5,    11,    12,
      13,    14,     9,     9,     9,     9,     9,     9,     9,     9,
       9,    16,    19,     9,     9,     9,   -27,    21,    15,     9,
      22,    23,    24,    25,   -53,     9,    43,   -20,     9,     9,
      27,     9,     9,    31,    32,    33,    36,    37,    38,    39,
      40,    42,     9,     9,   -53,   -53,   -53,    44,   -14,    45,
     -53,    47,    34,    71,   -53,   -53,   -53,   -53,   -53,    49,
       9,   -20,    50,    51,   -53,    52,    53,     9,     9,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,    54,    55,   -53,   -53,
      56,   -53,   -53,    34,    57,     9,    58,     9,    59,   -53,
     -53,   -53,   -53,    60,    61,   -53,   -53,   -53,   -53,     9,
      89,   -53,     9,   -53,    64,    65,    66,     9,    81,     9,
       9,   -53,    93,     9,    68,    69,     9,     9,    73,    75,
      95,    76,     9,     9,     9,   -53,    77,    78,    79,    82,
      86,   -53,   -53,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     5,     7,     6,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,     0,    44,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,    16,    44,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    17,    18,     0,     0,     0,
       9,     0,    46,     0,    45,    26,    27,    28,    15,     0,
       0,     0,     0,     0,    32,     0,     0,    44,    44,    39,
      40,    37,    38,    31,    19,    20,     0,     0,    25,    13,
       0,    10,     8,    46,     0,     0,     0,     0,     0,    23,
      24,    33,    36,     0,     0,    21,    22,    12,    47,     0,
       0,    29,     0,    30,     0,     0,     0,     0,     0,    44,
      44,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    44,     0,    41,     0,     0,     0,     0,
       0,    14,    34,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,    -2,   -52,    -7,    28,     4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    49,    57,    41,    50,   114
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,     3,    45,    42,    46,    91,    47,    40,    40,    43,
      44,     4,     5,     6,     7,    80,    48,    52,    53,    54,
      55,    56,    58,    59,     4,     5,     6,     7,   109,    70,
      71,    67,    68,    74,    40,    40,    72,    73,    40,   118,
      60,    77,    78,    79,    81,    61,    51,     4,     5,     6,
       7,    62,    63,    64,    65,    83,    92,    93,    75,    95,
      66,    76,    82,    69,    85,    86,    87,    88,    90,    94,
     106,   107,    97,    98,   113,    99,   110,    84,   100,   101,
     102,   103,   104,    89,   105,   115,   108,   111,   117,   112,
      96,   116,   119,   120,   121,   122,   125,   126,   127,   129,
     131,   133,   134,   135,   137,   139,   140,   143,   141,   146,
     148,   149,   154,   130,   152,   132,   153,   128,   155,   159,
     160,   161,   136,     0,   162,   123,   124,    40,   163,     0,
     138,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,   147,     0,     0,   150,   151,     0,   158,     0,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   145,     9,
      10,    11,     0,    12,     0,     0,    13,    14,    15,    16,
     156,   157,     0,     0,    17,    18,    19,    20,    21,    22,
      23,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,     0,     0,    36,
      37,    38,    39
};

static const yytype_int16 yycheck[] =
{
       2,     0,    40,    10,    40,    57,    40,     9,    10,    11,
      12,    38,    39,    40,    41,    42,     6,    19,    20,    42,
      41,    41,    24,    25,    38,    39,    40,    41,    42,    36,
      37,    33,    34,    40,    36,    37,    38,    39,    40,    91,
      40,    43,    44,    45,    46,    40,    18,    38,    39,    40,
      41,    40,    40,    40,    40,    40,    58,    59,    42,    61,
      32,    42,    41,    35,    42,    42,    42,    42,    25,    42,
      72,    73,    41,    41,    40,    42,    78,    49,    42,    42,
      42,    42,    42,    55,    42,    14,    42,    42,    90,    42,
      62,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    15,    41,    41,    26,    42,    16,
      42,    42,    17,   115,    41,   117,    41,   113,    42,    42,
      42,    42,   129,    -1,    42,    97,    98,   129,    42,    -1,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,   146,   147,    -1,   154,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    11,    12,    13,
     152,   153,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,    43,
      44,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,     0,    38,    39,    40,    41,    50,     3,
       4,     5,     7,    10,    11,    12,    13,    18,    19,    20,
      21,    22,    23,    24,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    40,    43,    44,    45,    46,
      50,    52,    52,    50,    50,    40,    40,    40,     6,    50,
      53,    53,    50,    50,    42,    41,    41,    51,    50,    50,
      40,    40,    40,    40,    40,    40,    53,    50,    50,    53,
      52,    52,    50,    50,    52,    42,    42,    50,    50,    50,
      42,    50,    41,    40,    53,    42,    42,    42,    42,    53,
      25,    51,    50,    50,    42,    50,    53,    41,    41,    42,
      42,    42,    42,    42,    42,    42,    50,    50,    42,    42,
      50,    42,    42,    40,    54,    14,    42,    50,    51,    42,
      42,    42,    42,    53,    53,    42,    42,    42,    54,    42,
      50,    42,    50,    42,    42,    42,    52,    15,    50,    41,
      41,    42,    50,    26,    53,    53,    16,    50,    42,    42,
      50,    50,    41,    41,    17,    42,    53,    53,    52,    42,
      42,    42,    42,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    51,    52,    52,    53,    53,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     5,     4,
       5,     8,     6,     5,    13,     4,     3,     4,     4,     4,
       4,     5,     5,     5,     5,     5,     4,     4,     4,     6,
       6,     4,     4,     5,    13,    13,     5,     4,     4,     4,
       4,     9,     1,     2,     0,     2,     0,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* input: seq  */
#line 522 "lisp.y"
                  { root = (yyvsp[0].node); (yyval.node) = (yyvsp[0].node); }
#line 1926 "lisp.tab.c"
    break;

  case 3: /* seq: seq expr  */
#line 526 "lisp.y"
                { (yyval.node) = make_node(NODE_SEQ, 0, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL); }
#line 1932 "lisp.tab.c"
    break;

  case 4: /* seq: %empty  */
#line 527 "lisp.y"
                { (yyval.node) = NULL; }
#line 1938 "lisp.tab.c"
    break;

  case 5: /* expr: NUMBER  */
#line 531 "lisp.y"
                                { (yyval.node) = make_node(NODE_NUMBER, (yyvsp[0].f), NULL, NULL, NULL, NULL); }
#line 1944 "lisp.tab.c"
    break;

  case 6: /* expr: ID  */
#line 532 "lisp.y"
                                { (yyval.node) = make_node(NODE_ID, 0, (yyvsp[0].s), NULL, NULL, NULL); }
#line 1950 "lisp.tab.c"
    break;

  case 7: /* expr: STRING  */
#line 533 "lisp.y"
                                { (yyval.node) = make_node(NODE_STRING, 0, (yyvsp[0].s), NULL, NULL, NULL); }
#line 1956 "lisp.tab.c"
    break;

  case 8: /* expr: '(' DEFINE ID expr ')'  */
#line 534 "lisp.y"
                                { (yyval.node) = make_node(NODE_DEFINE, 0, (yyvsp[-2].s), (yyvsp[-1].node), NULL, NULL); }
#line 1962 "lisp.tab.c"
    break;

  case 9: /* expr: '(' DEFINE ID ')'  */
#line 535 "lisp.y"
                           { (yyval.node) = make_node(NODE_DEFINE, 0, (yyvsp[-1].s), NULL, NULL, NULL); }
#line 1968 "lisp.tab.c"
    break;

  case 10: /* expr: '(' SET ID expr ')'  */
#line 536 "lisp.y"
                            { (yyval.node) = make_node(NODE_SET, 0, (yyvsp[-2].s), (yyvsp[-1].node), NULL, NULL); }
#line 1974 "lisp.tab.c"
    break;

  case 11: /* expr: '(' DEFUN ID '(' param_list ')' expr_list ')'  */
#line 537 "lisp.y"
                                                      { (yyval.node) = make_node(NODE_DEFUN, 0, (yyvsp[-5].s), (yyvsp[-3].node), (yyvsp[-1].node), NULL); }
#line 1980 "lisp.tab.c"
    break;

  case 12: /* expr: '(' IF expr expr expr ')'  */
#line 538 "lisp.y"
                                  { (yyval.node) = make_node(NODE_IF, 0, NULL, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1986 "lisp.tab.c"
    break;

  case 13: /* expr: '(' IF expr expr ')'  */
#line 539 "lisp.y"
                             { (yyval.node) = make_node(NODE_IF, 0, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL); }
#line 1992 "lisp.tab.c"
    break;

  case 14: /* expr: '(' LOOP FOR ID FROM expr TO expr BY expr DO expr_list ')'  */
#line 540 "lisp.y"
                                                                   { (yyval.node) = make_node_four(NODE_LOOP, 0, (yyvsp[-9].s), (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1998 "lisp.tab.c"
    break;

  case 15: /* expr: '(' DISPLAY expr ')'  */
#line 541 "lisp.y"
                             { (yyval.node) = make_node(NODE_DISPLAY, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2004 "lisp.tab.c"
    break;

  case 16: /* expr: '(' NEWLINE ')'  */
#line 542 "lisp.y"
                        { (yyval.node) = make_node(NODE_NEWLINE, 0, NULL, NULL, NULL, NULL); }
#line 2010 "lisp.tab.c"
    break;

  case 17: /* expr: '(' '+' expr_list ')'  */
#line 543 "lisp.y"
                              { (yyval.node) = make_node(NODE_ADD, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2016 "lisp.tab.c"
    break;

  case 18: /* expr: '(' '-' expr_list ')'  */
#line 544 "lisp.y"
                             { (yyval.node) = make_node(NODE_SUBTRACT, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2022 "lisp.tab.c"
    break;

  case 19: /* expr: '(' '*' expr_list ')'  */
#line 545 "lisp.y"
                              { (yyval.node) = make_node(NODE_MULTIPLY, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2028 "lisp.tab.c"
    break;

  case 20: /* expr: '(' '/' expr_list ')'  */
#line 546 "lisp.y"
                             { (yyval.node) = make_node(NODE_DIVIDE, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2034 "lisp.tab.c"
    break;

  case 21: /* expr: '(' '>' expr expr ')'  */
#line 547 "lisp.y"
                             { (yyval.node) = make_node(NODE_GREATER_THAN,  0, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL); }
#line 2040 "lisp.tab.c"
    break;

  case 22: /* expr: '(' '<' expr expr ')'  */
#line 548 "lisp.y"
                             { (yyval.node) = make_node(NODE_LESS_THAN,  0, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL); }
#line 2046 "lisp.tab.c"
    break;

  case 23: /* expr: '(' GREATER_EQ expr expr ')'  */
#line 549 "lisp.y"
                                    { (yyval.node) = make_node(NODE_GREATER_EQUAL, 0, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL); }
#line 2052 "lisp.tab.c"
    break;

  case 24: /* expr: '(' LESS_EQ expr expr ')'  */
#line 550 "lisp.y"
                                 { (yyval.node) = make_node(NODE_LESS_EQUAL, 0, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL); }
#line 2058 "lisp.tab.c"
    break;

  case 25: /* expr: '(' '=' expr expr ')'  */
#line 551 "lisp.y"
                             { (yyval.node) = make_node(NODE_EQUAL,  0, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL); }
#line 2064 "lisp.tab.c"
    break;

  case 26: /* expr: '(' AND arg_list ')'  */
#line 552 "lisp.y"
                             { (yyval.node) = make_node(NODE_AND, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2070 "lisp.tab.c"
    break;

  case 27: /* expr: '(' OR arg_list ')'  */
#line 553 "lisp.y"
                             { (yyval.node) = make_node(NODE_OR,  0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2076 "lisp.tab.c"
    break;

  case 28: /* expr: '(' NOT expr ')'  */
#line 554 "lisp.y"
                             { (yyval.node) = make_node(NODE_NOT, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2082 "lisp.tab.c"
    break;

  case 29: /* expr: '(' CLEAR '(' arg_list ')' ')'  */
#line 555 "lisp.y"
                                     { (yyval.node) = make_node(NODE_CLEAR, 0, NULL, (yyvsp[-2].node), NULL, NULL); }
#line 2088 "lisp.tab.c"
    break;

  case 30: /* expr: '(' TRIANGLE vertex vertex vertex ')'  */
#line 557 "lisp.y"
        {
            AST* vl = make_arglist((yyvsp[-3].node), make_arglist((yyvsp[-2].node), make_arglist((yyvsp[-1].node), NULL)));
            (yyval.node) = make_node(NODE_TRIANGLE, 0, NULL, vl, NULL, NULL);
        }
#line 2097 "lisp.tab.c"
    break;

  case 31: /* expr: '(' ID arg_list ')'  */
#line 562 "lisp.y"
                          { (yyval.node) = make_node(NODE_CALL, 0, (yyvsp[-2].s), (yyvsp[-1].node), NULL, NULL); }
#line 2103 "lisp.tab.c"
    break;

  case 32: /* expr: '(' REQ_ANIM_FRAME ID ')'  */
#line 563 "lisp.y"
                                { (yyval.node) = make_node(NODE_REQ_ANIM_FRAME, 0, (yyvsp[-1].s), NULL, NULL, NULL); }
#line 2109 "lisp.tab.c"
    break;

  case 33: /* expr: '(' SET_INTERVAL ID expr ')'  */
#line 564 "lisp.y"
                                   { (yyval.node) = make_node(NODE_SET_INTERVAL, 0, (yyvsp[-2].s), (yyvsp[-1].node), NULL, NULL); }
#line 2115 "lisp.tab.c"
    break;

  case 34: /* expr: '(' CUBE ID '(' arg_list ')' '(' arg_list ')' '(' arg_list ')' ')'  */
#line 565 "lisp.y"
                                                                         { (yyval.node) = make_node_four(NODE_CUBE, 0, (yyvsp[-10].s), (yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-2].node), NULL); }
#line 2121 "lisp.tab.c"
    break;

  case 35: /* expr: '(' SPHERE ID '(' arg_list ')' '(' arg_list ')' '(' arg_list ')' ')'  */
#line 566 "lisp.y"
                                                                           { (yyval.node) = make_node_four(NODE_SPHERE, 0, (yyvsp[-10].s), (yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-2].node), NULL); }
#line 2127 "lisp.tab.c"
    break;

  case 36: /* expr: '(' LINES ID arg_list ')'  */
#line 567 "lisp.y"
                                { (yyval.node) = make_node(NODE_LINES, 0, (yyvsp[-2].s), (yyvsp[-1].node), NULL, NULL); }
#line 2133 "lisp.tab.c"
    break;

  case 37: /* expr: '(' SIN expr ')'  */
#line 568 "lisp.y"
                       { (yyval.node) = make_node(NODE_SIN, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2139 "lisp.tab.c"
    break;

  case 38: /* expr: '(' COS expr ')'  */
#line 569 "lisp.y"
                       { (yyval.node) = make_node(NODE_COS, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2145 "lisp.tab.c"
    break;

  case 39: /* expr: '(' LIGHT ID ')'  */
#line 570 "lisp.y"
                       { (yyval.node) = make_node(NODE_LIGHT, 0, (yyvsp[-1].s), NULL, NULL, NULL); }
#line 2151 "lisp.tab.c"
    break;

  case 40: /* expr: '(' SET_LIGHT arg_list ')'  */
#line 571 "lisp.y"
                                 { (yyval.node) =  make_node(NODE_SET_LIGHT, 0, NULL, (yyvsp[-1].node), NULL, NULL); }
#line 2157 "lisp.tab.c"
    break;

  case 41: /* vertex: '(' COLOR expr expr expr POS expr expr ')'  */
#line 576 "lisp.y"
        {
            AST* rgb = make_arglist((yyvsp[-6].node), make_arglist((yyvsp[-5].node), make_arglist((yyvsp[-4].node), NULL)));
            AST* xy  = make_arglist((yyvsp[-2].node), make_arglist((yyvsp[-1].node), NULL));
            (yyval.node) = make_node(NODE_VERTEX, 0, NULL, rgb, xy, NULL);
        }
#line 2167 "lisp.tab.c"
    break;

  case 42: /* expr_list: expr  */
#line 584 "lisp.y"
                       { (yyval.node) = make_arglist((yyvsp[0].node), NULL); }
#line 2173 "lisp.tab.c"
    break;

  case 43: /* expr_list: expr expr_list  */
#line 585 "lisp.y"
                       { (yyval.node) = make_arglist((yyvsp[-1].node), (yyvsp[0].node));   }
#line 2179 "lisp.tab.c"
    break;

  case 44: /* arg_list: %empty  */
#line 589 "lisp.y"
                     { (yyval.node) = NULL; }
#line 2185 "lisp.tab.c"
    break;

  case 45: /* arg_list: expr arg_list  */
#line 590 "lisp.y"
                     { (yyval.node) = make_arglist((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2191 "lisp.tab.c"
    break;

  case 46: /* param_list: %empty  */
#line 594 "lisp.y"
                        { (yyval.node) = NULL; }
#line 2197 "lisp.tab.c"
    break;

  case 47: /* param_list: ID param_list  */
#line 595 "lisp.y"
                        { (yyval.node) = make_arglist(make_node(NODE_ID, 0, (yyvsp[-1].s), NULL, NULL, NULL), (yyvsp[0].node)); }
#line 2203 "lisp.tab.c"
    break;


#line 2207 "lisp.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 598 "lisp.y"


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
