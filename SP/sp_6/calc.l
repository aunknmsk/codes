%{
 
#include <stdio.h>
#include "y.tab.h"                        
int c;
extern int yylval;                      // acts as a communication medium between lex file and yacc file
%}
%%
" "       ;                             //If space is their don't do any thing

[a-z]     {
            c = yytext[0];
            yylval = c - 'a';                              // it calculates ascii value of the letter
            return(LETTER);                              // tells that this token is a letter
          }
[0-9]     {
            c = yytext[0];
            yylval = c - '0';                                             // it calculates ascii value of digit
            return(DIGIT);                                           // tells that this token is digit
          }
[^a-z0-9\b]    {
                 c = yytext[0];
                 return(c);                                         // if not digit or letter return value directly
               }
