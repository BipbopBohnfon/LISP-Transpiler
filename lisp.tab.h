/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LISP_TAB_H_INCLUDED
# define YY_YY_LISP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 502 "lisp.y"

    typedef struct AST AST;

#line 53 "lisp.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FOR = 258,                     /* FOR  */
    IF = 259,                      /* IF  */
    THEN = 260,                    /* THEN  */
    ELSE = 261,                    /* ELSE  */
    SET = 262,                     /* SET  */
    DEFINE = 263,                  /* DEFINE  */
    DEFUN = 264,                   /* DEFUN  */
    LOOP = 265,                    /* LOOP  */
    FROM = 266,                    /* FROM  */
    TO = 267,                      /* TO  */
    BY = 268,                      /* BY  */
    DO = 269,                      /* DO  */
    AND = 270,                     /* AND  */
    OR = 271,                      /* OR  */
    NOT = 272,                     /* NOT  */
    DISPLAY = 273,                 /* DISPLAY  */
    NEWLINE = 274,                 /* NEWLINE  */
    CLEAR = 275,                   /* CLEAR  */
    TRIANGLE = 276,                /* TRIANGLE  */
    COLOR = 277,                   /* COLOR  */
    POS = 278,                     /* POS  */
    GREATER_EQ = 279,              /* GREATER_EQ  */
    LESS_EQ = 280,                 /* LESS_EQ  */
    REQ_ANIM_FRAME = 281,          /* REQ_ANIM_FRAME  */
    SET_INTERVAL = 282,            /* SET_INTERVAL  */
    LINES = 283,                   /* LINES  */
    CUBE = 284,                    /* CUBE  */
    SPHERE = 285,                  /* SPHERE  */
    LIGHT = 286,                   /* LIGHT  */
    SET_LIGHT = 287,               /* SET_LIGHT  */
    SIN = 288,                     /* SIN  */
    COS = 289,                     /* COS  */
    NUMBER = 290,                  /* NUMBER  */
    STRING = 291,                  /* STRING  */
    ID = 292                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 506 "lisp.y"

    float f;
    char* s;
    AST* node;

#line 113 "lisp.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LISP_TAB_H_INCLUDED  */
