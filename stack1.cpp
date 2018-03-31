#include"stdio.h"
#include"stdlib.h"
struct stack{
	int data;
	struct stack *next;
};
typedef struct stack node;
node *p=NULL;

void push(int deger){
	
	if(p==NULL){
		p=(stack*)malloc(sizeof(stack));
		p->next=NULL;
			p->data=deger;
	}

	node *temp;
	temp=(stack*)malloc(sizeof(stack));
	temp->data=deger;
	temp->next=p;
	p=temp;
}

int pop(){
	if(p->next==NULL){
		return -1;
	}
	node *temp;
	int result;
	temp=p;
	result=temp->data;
	p=p->next;
	free(temp);
	return result;
}

void show(){
	printf("stack:\n");
	node *temp=p;
	while(temp->next!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}



int main(){
	
	push(10);
	push(20);
	push(30);
	show();
	pop();
	pop();
	show();
	pop();
	pop();
	pop();
	show();
	push(80);
	push(64);
	push(24);
	push(12);
	show();
	pop();
	show();
	
	
	
	
}
