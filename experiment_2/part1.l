%option noyywrap

%{
     #include<stdio.h>
     int vowels=0, consonants=0;   
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z]     {consonants++;}
.|\n         {/*ignore*/}
%%

int main(){
    printf("Enter a string (press ctrl + D) : ");
    yylex();
    printf("vowels : %d\nconsonants : %d\n",vowels,consonants);
    return 0;
}