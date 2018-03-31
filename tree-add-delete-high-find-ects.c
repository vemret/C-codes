#include<stdio.h>
#include<stdlib.h>

struct n{
	int data;
	struct n *left;
	struct n *right;
};
typedef struct n node;

node *add(node *agac,int veri){
	if(agac==NULL){
		node *root=(node*)malloc(sizeof(node));
		root->right=NULL;
		root->left=NULL;
		root->data=veri;
		return root;
	}
	if(agac->data<veri){
		agac->right=add(agac->right,veri);
		return agac;
	}
	agac->left=add(agac->left,veri);
	return agac;
}

void yazdir(node *agac){
	if(agac==NULL)
		return;
	
	printf("%d\t",agac->data);
	
	yazdir(agac->left);
	yazdir(agac->right);	
}
int find(node *agac,int x){
	if(agac==NULL){
		//printf("agac bos\n");
		return -1;
	}
	if(agac->data==x)
		return 1;
	if(find(agac->right,x)==1){
		return 1;
		//printf("aranan deger bulundu\n");
	}
	if(find(agac->left,x)==1){
		return 1;
		//printf("aranan deger bulundu\n");
	}
	return -1;
}
int min(node *agac){
	while(agac->left!=NULL){
		agac=agac->left;
	}
	return agac->data;
}
 
 int max(node *agac){
 	while(agac->right!=NULL){
 		agac=agac->right;
	 }
	 return agac->data;
 }
 node *del(node *agac,int veri){
 	if(agac==NULL){
//		printf("agac bos\n");
 		return;
 	}
 	if(agac->data==veri){
 		if(agac->right==NULL && agac->left==NULL)
			return NULL;
	 
	 	if(agac->right!=NULL){
	 		agac->data=min(agac->right);
	 		agac->right=del(agac->right,min(agac->right));
	 		return agac;
		 }
		 agac->data=max(agac->left);
		 agac->left=del(agac->left,max(agac->left));
		 return agac;
 	}
 	 if(agac->data<veri){
 	 	agac->right=del(agac->right,veri);
 	 	return agac;
 	  }
	  	agac->left=del(agac->left,veri);	
	  	return agac;
 }

int yukseklik(node *agac){
	if(agac==NULL){
		//printf("agac bos\n");
		return -1;
	}
	int sag,sol;
	sag=yukseklik(agac->right);
	sol=yukseklik(agac->left);
	if(sag>sol){
		return sag+1;
	}
	else{
		return sol+1;
	}
}
int size(node *agac){
	if(agac==NULL){
		//printf("agac bos\n");
		return;
	}
	else
	return size(agac->right)+1+size(agac->left);
}
void mirror(node *agac){
	if(agac==NULL){
	//	printf("agac bos\n");
		return;
	}
	else{
	node *temp;
	mirror(agac->right);
	mirror(agac->left);
	temp=agac->left;
	agac->left=agac->right;
	agac->right=temp;
	}
}

int main(){
	node *agac=NULL;
	agac=add(agac,50);
	agac=add(agac,35);
	agac=add(agac,94);
	agac=add(agac,98);
	agac=add(agac,12);
	agac=add(agac,65);
	agac=add(agac,45);
	agac=add(agac,100);
	agac=add(agac,2);
	agac=add(agac,34);
	agac=add(agac,27);
	agac=add(agac,19);
	agac=add(agac,83);
	agac=add(agac,52);
	agac=add(agac,77);
//	int x=size(agac);
	printf("dugum sayisi: %d/\n",size(agac));
	printf("yukseklik: %d\n",yukseklik(agac));
	printf("min:%d\n",min(agac));
	printf("max:%d\n",max(agac));
	yazdir(agac);
	printf("\n");
	agac=del(agac,35);
	yazdir(agac);
//	find(agac,45);
//	find(agac,52);
	printf("\n");
	yazdir(agac);
	printf("\n");
	agac=del(agac,11);
	agac=del(agac,52);
	printf("dugum sayisi: %d\n",size(agac));
	printf("yukseklik: %d\n",yukseklik(agac));
	yazdir(agac);
	mirror(agac);
	yazdir(agac);
	
return 0;	
}
