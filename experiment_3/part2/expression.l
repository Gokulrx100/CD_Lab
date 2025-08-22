%option noyywrap
%{
#include "y.tab.h"
%}

%%

[0-9]+              { yylval = atoi(yytext); return NUMBER; }

[ \t\n]             { /* ignore whitespace */ }

"("                 { return '('; }
")"                 { return ')'; }
"+"                 { return '+'; }
"-"                 { return '-'; }
"*"                 { return '*'; }
"/"                 { return '/'; }

.                   { return yytext[0]; }   /* catch-all for other characters */

%%

