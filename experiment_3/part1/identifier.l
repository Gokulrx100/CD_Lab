%option noyywrap

%{
    #include "y.tab.h"
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* {return IDENTIFIER;}
.|\n {return yytext[0]}
%%