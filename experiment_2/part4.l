%option noyywrap

%{
#include<stdio.h>
%}

%%
([a-zA-Z0-9][a-zA-Z0-9._]*)@([a-zA-Z0-9]+)\.com {printf("Valid Email");}

.* {printf("Invalid Email");}
%%

int main(){
    printf("Enter an email : ");
    yylex();
    return 0;
}