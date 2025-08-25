%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
%}

%token NUMBER

%left '+' '-'        /* lowest precedence */
%left '*' '/'        /* higher precedence */
%left UMINUS         /* unary minus (highest precedence) */

%%

input:
      expr   { printf("\nValid expression\n"); exit(0); }
    ;

expr:
      expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '-' expr %prec UMINUS   /* unary minus */
    | '(' expr ')'
    | NUMBER
    ;

%%

int main() {
    printf("Enter an expression(press ctrl + D) : ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("invalid expression");
    return 0;
}
