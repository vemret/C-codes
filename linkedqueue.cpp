#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct lnode{
        int data;
        lnode * next;        
} ;
typedef struct lnode lnode;
lnode * root;
int size=0;
int dequeue(){
    if(size==0)
               return -1;
    if(size==1){
                int result = root->data;
                root=NULL;
                size--;
                return result;
                }
          lnode * iter;
          iter = root;
          for(int i = 0;i<size-2;i++){
                  iter = iter->next;
          }
          lnode * temp = iter->next;
          int result = iter->next->data;
          iter->next = NULL;
          free(temp);
          size--;
          return result;
}
void enqueue(int data){
     if(size==0){
                 root = (lnode*)malloc(sizeof(lnode));
                 root->data=data;            
                 root->next = NULL;
                 size++;
     }
     else{    
          lnode * iter=(lnode*)malloc(sizeof(lnode));
          iter->data=data;
          iter->next=root;
          size++;
          root=iter;
     }
}
void printqueue(){
     lnode  *iter;
     iter=root;
     printf("\n");
     for(int i = 0;i<size;i++){
             printf("%d__",iter->data);
             iter=iter->next;
     }
}
int main(){
 enqueue(10);
 printqueue();
 enqueue(20);
 printqueue();
 printf("\ndequeue -> %d",dequeue());
 printqueue(); 
 enqueue(30);
  printqueue(); 
 enqueue(40);
  printqueue(); 
 printf("\ndequeue -> %d",dequeue());
  printqueue(); 
 printf("\ndequeue -> %d",dequeue());
  printqueue(); 
 printf("\ndequeue -> %d",dequeue());
  printqueue(); 
 printf("\ndequeue -> %d",dequeue());
  printqueue(); 
 getch();
 return 0;   
}
