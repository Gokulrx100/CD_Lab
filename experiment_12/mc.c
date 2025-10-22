#include<stdio.h>
#include<string.h>

char tac[100][100];
int n,rc=0;

struct code{
	char arg1[10];
	char arg2[10];
	char opcode[10];
}mc[20];
int mcc = 0;

void computemc(){
	for(int i=0;i<n;i++){
		sprintf(mc[mcc].arg1,"R%d",rc);
		sprintf(mc[mcc].arg2,"%c",tac[i][2]);
		strcpy(mc[mcc++].opcode,"MOV");
		sprintf(mc[mcc].arg1,"R%d",rc);
		sprintf(mc[mcc].arg2,"%c",tac[i][4]);
		switch(tac[i][3]){
			case '+':strcpy(mc[mcc++].opcode,"ADD");break;
			case '-':strcpy(mc[mcc++].opcode,"SUB");break;
			case '*':strcpy(mc[mcc++].opcode,"MUL");break;
			case '/':strcpy(mc[mcc++].opcode,"DIV");break;
		}
		sprintf(mc[mcc].arg1,"%c",tac[i][0]);
		sprintf(mc[mcc].arg2,"R%d",rc);
		strcpy(mc[mcc++].opcode,"MOV");
		rc++;
	}
}

void printmc(){
	for(int i=0;i<mcc;i++){
		printf("\n%s %s,%s",mc[i].opcode ,mc[i].arg1,mc[i].arg2);
	}
	printf("\n");
}

void main(){
	printf("Enter the number of intermediate statements: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf(" %s",tac[i]);
	}
	computemc();
	printmc();
}