%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

FILE *fp_out;

char *keywords[] = {
    "break","case","char","const","continue","default","do",
    "else","enum","float","for","goto","if","int","return",
    "sizeof","static","struct","switch","union",
    "void","while"
};

// Check if a word is a keyword
int isKeyword(const char *word) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}
%}

%%

"#"[a-zA-Z]+      {fprintf(fp_out, "Preprocessor Directive: %s\n", yytext);}

[0-9]+            { fprintf(fp_out, "Number: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* {
                     if (isKeyword(yytext))
                         fprintf(fp_out, "Keyword: %s\n", yytext);
                     else
                         fprintf(fp_out, "Identifier: %s\n", yytext);
                  }

"+"|"-"|"*"|"/"|"="|"<"|">" {fprintf(fp_out, "Operator: %s\n", yytext);}

";"|","|"("|")"|"{"|"}"|"["|"]" {fprintf(fp_out, "Separator: %s\n", yytext);}

[ \t\n]+          {/*ignore*/}

.                 { /* ignore other characters */ }

%%

int main(int argc, char **argv) {
    FILE *fp_in = fopen("input.c", "r");
    if (!fp_in) {
        printf("Error opening input file!\n");
        return 1;
    }

    fp_out = fopen("output.txt", "w");
    if (!fp_out) {
        printf("Error creating output file!\n");
        fclose(fp_in);
        return 1;
    }

    yyin = fp_in;
    yylex();

    fclose(fp_in);
    fclose(fp_out);
    printf("Lexical analysis complete! Tokens written to output.txt\n");
    return 0;
}
