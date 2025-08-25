#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char *input;
char lookahead;

void next() { lookahead = *input++; }

void error() {
    printf("Syntax error at '%c'\n", lookahead);
    exit(1);
}

void E(); 
void Eprime(); 
void T(); 
void Tprime(); 
void F();

// E -> T E'
void E() {
    T();
    Eprime();
}

// E' -> T E' | ε
void Eprime() {
    if (isalnum(lookahead) || lookahead == '(') {  
        T();
        Eprime();
    }
    // else epsilon (do nothing)
}

// T -> F T'
void T() {
    F();
    Tprime();
}

// T' -> * F T' | ε
void Tprime() {
    if (lookahead == '*') {
        next();
        F();
        Tprime();
    }
    // else epsilon (do nothing)
}

// F -> (E) | id
void F() {
    if (lookahead == '(') {
        next();
        E();
        if (lookahead == ')') next();
        else error();
    } 
    else if (isalpha(lookahead)) {  // id
        next();
    } 
    else {
        error();
    }
}

int main() {
    char expr[100];
    printf("Enter expression: ");
    scanf("%s", expr);

    input = expr;
    next();
    E();

    if (lookahead == '\0')
        printf("Valid expression\n");
    else
        error();

    return 0;
}
