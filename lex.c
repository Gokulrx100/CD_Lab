#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] = {
    "break","case","char","const","continue","default","do",
    "else","enum","extern","float","for","goto","if","int","return",
    "signed", "sizeof","static","struct","switch","union","unsigned",
    "void","volatile", "while"
};

// Check if a word is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[50];
    FILE *fp_in, *fp_out;
    int j = 0;

    // Open input file
    fp_in = fopen("input.c", "r");
    if (fp_in == NULL) {
        printf("Error opening input file!\n");
        return 0;
    }

    // Open output file
    fp_out = fopen("output.txt", "w");
    if (fp_out == NULL) {
        printf("Error creating output file!\n");
        fclose(fp_in);
        return 0;
    }

    while ((ch = fgetc(fp_in)) != EOF) {
        // Preprocessor directive (#)
        if (ch == '#') {
            fprintf(fp_out, "Preprocessor Directive: #");
            j = 0;
            while ((ch = fgetc(fp_in)) != EOF && isalpha(ch)) {
                buffer[j++] = ch;
            }
            buffer[j] = '\0';
            fprintf(fp_out, "%s\n", buffer);
            j = 0;
        }

        // Identifiers or numbers
        else if (isalnum(ch)) {
            buffer[j++] = ch;
        }

        // Separators
        else {
            if (j > 0) {
                buffer[j] = '\0';
                j = 0;

                if (isKeyword(buffer))
                    fprintf(fp_out, "Keyword: %s\n", buffer);
                else if (isdigit(buffer[0]))
                    fprintf(fp_out, "Number: %s\n", buffer);
                else
                    fprintf(fp_out, "Identifier: %s\n", buffer);
            }

            // Operators
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ||
                ch == '<' || ch == '>') {
                fprintf(fp_out, "Operator: %c\n", ch);
            }

            // Special symbols
            if (ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
                ch == '{' || ch == '}' || ch == '[' || ch == ']') {
                fprintf(fp_out, "Seperator: %c\n", ch);
            }
        }
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("Lexical analysis complete! Tokens written to output.txt\n");
    return 0;
}
