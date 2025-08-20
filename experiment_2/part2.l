%option noyywrap

%{
    #include<stdio.h>
    int chars=0,words=0,lines=0;
%}

%%
\n  {lines++;}
[ \t]+   {/*ignore*/}
[a-zA-Z0-9]+ {words++; chars+=yyleng;}
.   {/*ignore*/}
%%

int main(){
    yyin = fopen("input.txt","r");
    if(!yyin){
        printf("Could not open file");
        return 1;
    }

    yylex();

    fclose(yyin);

    if(words>0 || chars>0){
        lines++;
    }

    printf("Characters : %d\nWords : %d\nLines : %d\n",chars,words,lines);
    return 0;

}