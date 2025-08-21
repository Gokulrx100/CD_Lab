%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
%}

%token NUMBER

%left '+' '-'       
%left '*' '/'  
%left UMINUS         

%%

input:
      expr   { printf("Valid expression\n"); exit(0); }
    ;

expr:
      expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '-' expr %prec UMINUS  
    | '(' expr ')'
    | NUMBER
    ;

%%

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    return 0;
}