%{
#include <stdlib.h>
#include <string.h>
#include "lisp.tab.h"

%}

%%

"define"    { return DEFINE; }
"defun"     { return DEFUN; }
"set!"      { return SET; }
"if"        { return IF; }
"then"      { return THEN; }
"else"      { return ELSE; }
"for"       { return FOR; }
"from"      { return FROM; }
"to"        { return TO; }
"by"        { return BY; }
"do"        { return DO; }
"and"       { return AND; }
"or"        { return OR; }
"not"       { return NOT; }
">="        { return GREATER_EQ; }
"<="        { return LESS_EQ; }
"loop"      { return LOOP; }
"display"   { return DISPLAY; }
"newline"   { return NEWLINE; }
"clear"     { return CLEAR; }
"triangle"  { return TRIANGLE; }
"color"     { return COLOR; }
"pos"       { return POS; }

"reqanimframe"      { return REQ_ANIM_FRAME; }
"setinterval"       { return SET_INTERVAL; }
"lines"             { return LINES; }
"cube"              { return CUBE; }
"sphere"            { return SPHERE; }
"light"             { return LIGHT; }
"setlight"          { return SET_LIGHT; }
"sin"               { return SIN; }
"cos"               { return COS; }

-[0-9]+\.[0-9]*  { yylval.f = atof(yytext); return NUMBER; }
-\.[0-9]+        { yylval.f = atof(yytext); return NUMBER; }
-[0-9]+          { yylval.f = atof(yytext); return NUMBER; }

[0-9]+\.[0-9]*   { yylval.f = atof(yytext); return NUMBER; }
\.[0-9]+         { yylval.f = atof(yytext); return NUMBER; }
[0-9]+           { yylval.f = atof(yytext); return NUMBER; }

\"([^\"\\]|\\.)*\"  {   char* str = strdup(yytext);
                        if (strstr(str, "~%") != NULL) {
                            char* pos;
                            while ((pos = strstr(str, "~%")) != NULL) {
                                *pos = '\\';
                                *(pos+1) = 'n';
                            }
                        }
                        yylval.s = str;
                        return STRING;
                    }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.s = strdup(yytext); return ID; }

"+"  { return '+'; }
"-"  { return '-'; }
"*"  { return '*'; }
"/"  { return '/'; }
">"  { return '>'; }
"<"  { return '<'; }
"="  { return '='; }
"("  { return '('; }
")"  { return ')'; }

";"[^\n]*  ;

[ \t\r\n]+  ;

.  { return yytext[0]; }

%%

int yywrap(void) { return 1; }
