#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 100
int stack[MAXSTACK];
int top=-1;
int isEmpty();
void push(int);
int pop();


int main(int argc, char *argv[]){
	int value;
	int i;
	printf("insert 10 values\n");
	for(i=0;i<10;i++){
		scanf("%d",&value);
		push(value);

	}
	printf("=========================\n");
	while(!isEmpty()){
		printf("%d\n",pop());
	}
	pop();
	return 0;
}

int isEmpty(){
	if(top==-1){
		return 1;
	}else{
		return 0;
	}
}

void push(int item){
	if(top>=MAXSTACK){
		printf("stack full!!!");
	}else{
		top++;
		stack[top]=item;
	}
}

int pop(){
	int item;
	if(isEmpty()){
		printf("stack empty!!!");
	}else{
		item=stack[top];
		top--;
		return item;
	}
}
