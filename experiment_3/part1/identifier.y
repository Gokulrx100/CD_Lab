%{
#include <stdio.h>
#include <stdlib.h>
%}

%token IDENTIFIER

%%
input: IDENTIFIER    { printf("Valid identifier\n"); exit(0); }
     | error         { printf("Invalid identifier\n"); exit(1); }
     ;
%%

int main() {
    printf("Enter an identifier: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    return 0;
}
