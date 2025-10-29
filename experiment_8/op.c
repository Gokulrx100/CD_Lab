// #include<stdio.h>
// #include<string.h>

// char str[100], stack[100];
// int top = -1;

// void print(char* input,char* action){
//     printf("%s\t\t", input);
//     for(int j=0; j<=top; j++)
//         printf("%c", stack[j]);
//     printf("\t\t%s\n", action);

// }

// void main(){
//     printf("Enter the string: ");
//     scanf("%s", str);

//     int len = strlen(str);
//     str[len] = '$';
//     str[len+1] = '\0';

//     printf("Input\t\tStack\t\tAction\n");

//     int i=0;
//     while(1){
//         if(str[i]=='i'){  
//             print(str+i, "Shift i");
//             stack[++top]='i';
//             i++;

//             print(str+i, "Reduce i -> E");
//             stack[top]='E';
//         }
//         else if(top>1 && stack[top]=='E' && stack[top-1]=='*' && stack[top-2]=='E'){
//             print(str+i, "Reduce E*E -> E");
//             stack[top-2]='E';
//             top -=2;
//         }
//         else if(str[i]=='*'){
//             print(str+i, "Shift *");
//             stack[++top]='*';
//             i++;
//         }
//         else if(top>1 && stack[top]=='E' && stack[top-1]=='+' && stack[top-2]=='E'){
//             print(str+i, "Reduce E+E -> E");
//             stack[top-2]='E';
//             top -=2;
//         }
//         else if(str[i]=='+'){
//             print(str+i, "Shift +");
//             stack[++top] = str[i];
//             i++;
//         }
//         else if(str[i]=='$' && stack[top]=='E' && top==0){
//             print(str+i, "Accept");
//             break;
//         }
//         else{
//             print(str+i, "Error");
//             break;
//         }
//     }
// }


#include<stdio.h>
#include<string.h>

char str[100], stack[100];
int top=-1;

void print(char* input, char* action){
    printf("%s\t\t",input);
    for(int j=0; j<=top; j++){
        printf("%c",stack[j]);
    }
    printf("\t\t%s\n",action);
}

int precedence(char op){
    switch(op){
    case '+':
    return 1;
    // case '-':
    // return 1;
    case '*':
    return 2;
    // case '/':
    // return 2;
    // case '^':
    // return 3;
    deafult:
    return 0;
    }
}

int isOperator(char c){
    // return (c=='+' || c=='-' || c=='/' || c=='*' || c=='^');
    return (c=='+' || c=='*');
}

void reduce(){
    if(top>=2 && stack[top]=='E' && isOperator(stack[top-1]) && stack[top-2]=='E'){
        print("", "Reduce E op E->E");
            stack[top-2]='E';
            top-=2;
    }
    //this is for (E)
    // if(top>=2 && stack[top]=='E' && stack[top-1]=='(' && stack[top-2]==')'){
    //     print("", "Reduce (E)->E");
    //         stack[top-2]='E';
    //         top-=2;
    // }
}

void main(){
    printf("Enter an expression : ");
    scanf("%s",str);

    int len=strlen(str);
    str[len]='$';
    str[len+1]='\0';

    int i=0;
    while(1){
        if(str[i]=='i'){
            print(str+i, "Shift i");
            stack[++top]='i';
            i++;

            print(str+i, "Reduce i->E");
            stack[top]='E';
        }
        // else if(str[i]=='('){
        //     print(str+i, "Shift )");
        //     stack[++top]='(';
        //     i++;
        // }
        // else if(str[i]==')'){
        //     print(str+i,"Shift )");
        //     stack[++top]=')';
        //     i++;

        //     while (top>=2 && stack[top] == 'E' && stack[top-1]==')' && stack[top-2]=='('){
        //         reduce();
        //     }
        // }
        else if(isOperator(str[i])){
            while (top >= 2 && isOperator(stack[top - 1]) &&
                   ((precedence(stack[top - 1]) > precedence(str[i])) ||
                    (precedence(stack[top - 1]) == precedence(str[i]) && str[i] != '^'))){
                reduce();
            }
            print(str+i, "Shift operator");
            stack[++top]=str[i];
            i++;
        }
        else if(top==0 && stack[top]=='E' && str[i]=='$'){
            print(str+i, "Accept");
            break;
        }
        else{
            print(str+i, "Error");
            break;
        }
    }
}