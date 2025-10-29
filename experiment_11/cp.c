#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char postfix[100];

struct threeAC {
    char arg1[10];
    char arg2[10];
    char op;
    char result[10];
} tac[100];

int tacc = 0;
int pf = 0;

struct {
    char name[10];
    int value;
} vars[100];
int varCount = 0;

int precedence(char a) {
    switch (a) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void convertToPostfix(char *input) {
    int i = 0, top = -1;
    pf = 0;
    char stack[100];

    while (input[i] != '\0') {
        if (isalnum(input[i])) {
            postfix[pf++] = input[i++];
        }
        else if (input[i] == '(') {
            stack[++top] = input[i++];
        }
        else if (input[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[pf++] = stack[top--];
            top--;
            i++;
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(input[i]))
                postfix[pf++] = stack[top--];
            stack[++top] = input[i++];
        }
    }
    while (top != -1)
        postfix[pf++] = stack[top--];

    postfix[pf] = '\0';
}

void find3AC(char *postfix) {
    char stack[100][100];
    int top = -1, t = 0;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            sprintf(stack[++top], "%c", postfix[i]);
        }
        else {
            strcpy(tac[tacc].arg2, stack[top--]);
            strcpy(tac[tacc].arg1, stack[top--]);
            tac[tacc].op = postfix[i];
            sprintf(tac[tacc].result, "t%d", t);
            sprintf(stack[++top], "t%d", t++);
            tacc++;
        }
    }
}

int findVarValue(char *name) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(vars[i].name, name) == 0)
            return vars[i].value;
    }
    return atoi(name);
}

void constantPropagation() {
    for (int i = 0; i < tacc; i++) {
        char *a1 = tac[i].arg1, *a2 = tac[i].arg2;

        for (int j = 0; j < varCount; j++) {
            if (strcmp(a1, vars[j].name) == 0)
                sprintf(a1, "%d", vars[j].value);

            if (strcmp(a2, vars[j].name) == 0)
                sprintf(a2, "%d", vars[j].value);
        }
    }
}

void evaluate() {
    for (int i = 0; i < tacc; i++) {
        int val1 = findVarValue(tac[i].arg1);
        int val2 = findVarValue(tac[i].arg2);
        int res = 0;

        switch (tac[i].op) {
            case '+': res = val1 + val2; break;
            case '-': res = val1 - val2; break;
            case '*': res = val1 * val2; break;
            case '/': res = val1 / val2; break;
        }

        strcpy(vars[varCount].name, tac[i].result);
        vars[varCount].value = res;
        varCount++;
    }
}

void print3AC() {
    printf("\nThree Address Code:\n");
    for (int i = 0; i < tacc; i++) {
        printf("%s = %s %c %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
    }
}

void main() {
    char input[100];

    printf("Enter the input expression (eg: a*b+x-y): ");
    scanf("%s", input);

    printf("\nEnter the value of a: ");
    scanf("%d", &vars[varCount].value);
    strcpy(vars[varCount++].name, "a");

    printf("Enter the value of b: ");
    scanf("%d", &vars[varCount].value);
    strcpy(vars[varCount++].name, "b");

    printf("Enter the value of x: ");
    scanf("%d", &vars[varCount].value);
    strcpy(vars[varCount++].name, "x");

    printf("Enter the value of y: ");
    scanf("%d", &vars[varCount].value);
    strcpy(vars[varCount++].name, "y");

    convertToPostfix(input);
    printf("\nPostfix Expression: %s\n", postfix);

    find3AC(postfix);
    print3AC();

    constantPropagation();
    printf("\nAfter Constant Propagation:\n");
    print3AC();

    evaluate();
    printf("\nFinal Result = %d\n", vars[varCount - 1].value);
}
