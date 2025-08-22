%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

input:
    | input line
    ;

line:
      '\n'
    | expr '\n'   { printf("Result = %d\n", $1); }
    ;

expr:
      NUMBER                  { $$ = $1; }
    | expr '+' expr           { $$ = $1 + $3; }
    | expr '-' expr           { $$ = $1 - $3; }
    | expr '*' expr           { $$ = $1 * $3; }
    | expr '/' expr           { 
                                  if ($3 == 0) {
                                      printf("Error: Division by zero!\n");
                                      exit(1);
                                  }
                                  $$ = $1 / $3; 
                               }
    | '-' expr %prec UMINUS   { $$ = -$2; }
    | '(' expr ')'            { $$ = $2; }
    ;

%%

int main() {
    printf("Enter expressions (Ctrl+D to quit):\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
