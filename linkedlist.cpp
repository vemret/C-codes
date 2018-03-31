#include<stdio.h>
#include"stdlib.h"
struct student{
	int no;
	int age;
	char name[10];
	struct student *next;
};
typedef struct student node;
node *head,*newnode;
int main(){
	int n,i=0;
			newnode=(node*)malloc(sizeof(node));
			head=newnode;
		printf("ogrenci no -1 girilene kadar veri gir\n");
	while(newnode->no!=-1){
			newnode->next=(node*)malloc(sizeof(node));
			newnode=newnode->next;
		printf("%d. student No: ",i+1);		 scanf("%d",&newnode->no);
		if(newnode->no!=-1){
		printf("%d. student Age: ",i+1);	 scanf("%d",&newnode->age);
		printf("%d.student Name: ",i+1);	 scanf("%s",newnode->name);
	}
			i++;
	}
	newnode->next=NULL;
	
	int ct=1;
	node *p;
	p=head;
	while(p->next->next!=NULL){
		printf("%d. student No: %d \n",ct,newnode->no);
		printf("%d. student Age: %d\n ",ct,newnode->age);
		printf("%d.student Name: %s\n ",ct,newnode->name);
		p=p->next;
		ct++;
	}
	
}

