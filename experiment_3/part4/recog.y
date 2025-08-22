%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
%}

%token A B

%%

start: S '\n'    { printf("Valid string: a^n b^n\n"); exit(0); }
     ;

S: A S B         
 | A B           /* base case */
 ;

%%

int main() {
    printf("Enter a string of the form a^n b^n:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    printf("Invalid string\n");
    exit(1);
}
