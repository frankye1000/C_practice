#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

typedef struct Node Stack_Node;//alias=nickname
typedef Stack_Node *Linked_Stack;
Linked_Stack top=NULL;
int isEmpty();
void push(int);
int pop();


int main(int argc, char *argv[]){
	int value;
	int i;
	printf("insert value\n");
	for(i=0;i<10;i++){
		scanf("%d",&value);
		push(value);
	}
	printf("=============================\n");
	while(!isEmpty()){
		printf("pop stack:%d\n",pop());
	}
	pop();
	return 0;
}


int isEmpty(){
	if(top==NULL){
		return 1;
	}else{
		return 0;
	}
}


void push(int item){
	Linked_Stack new_add_node;//pointer
	new_add_node=(Linked_Stack)malloc(sizeof(Stack_Node));//make new memory space
	new_add_node->data=item;
	new_add_node->next=top;
	top=new_add_node;
}

int pop(){
	Linked_Stack ptr;//pointer
	int item;
	if(isEmpty()){
		printf("stack is empty~~~~\n");
		return -1;
	}else{
		ptr=top;
		item=ptr->data;
		top=top->next;
		free(ptr);
		return item;
	}
}
