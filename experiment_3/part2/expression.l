%option noyywrap

%{
#include "y.tab.h"
%}

%%

[0-9]+      { return NUMBER; }
[ \t\n]     { /* ignore whitespace */ }
.           { return yytext[0]; }

%%
