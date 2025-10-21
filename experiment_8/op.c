#include<stdio.h>
#include<string.h>

char str[100], stack[100];
int top = -1;

void print(char* input,char* action){
    printf("%s\t\t", input);
    for(int j=0; j<=top; j++)
        printf("%c", stack[j]);
    printf("\t\t%s\n", action);

}

void main(){
    printf("Enter the string: ");
    scanf("%s", str);

    int len = strlen(str);
    str[len] = '$';
    str[len+1] = '\0';

    printf("Input\t\tStack\t\tAction\n");

    int i=0;
    while(1){
        if(str[i]=='i'){  
            print(str+i, "Shift i");
            stack[++top]='i';
            i++;

            print(str+i, "Reduce i -> E");
            stack[top]='E';
        }
        else if(top>1 && stack[top]=='E' && stack[top-1]=='*' && stack[top-2]=='E'){
            print(str+i, "Reduce E*E -> E");
            stack[top-2]='E';
            top -=2;
        }
        else if(str[i]=='*'){
            print(str+i, "Shift *");
            stack[++top]='*';
            i++;
        }
        else if(top>1 && stack[top]=='E' && stack[top-1]=='+' && stack[top-2]=='E'){
            print(str+i, "Reduce E+E -> E");
            stack[top-2]='E';
            top -=2;
        }
        else if(str[i]=='+'){
            print(str+i, "Shift +");
            stack[++top] = str[i];
            i++;
        }
        else if(str[i]=='$' && stack[top]=='E' && top==0){
            print(str+i, "Accept");
            break;
        }
        else{
            print(str+i, "Error");
            break;
        }
    }
}