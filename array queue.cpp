#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int *a;
int size=0;
void enqueue(int data){
 int * b = (int * ) malloc(sizeof(int)*size+1);
 int i=0;
 for(i = 0;i<size;i++){
         b[i]=a[i];
 }  
 b[i]=data;
 size++;
 a=b;
}
int dequeue(){
    if(size<=0)
               return -1;

 int * b = (int * ) malloc(sizeof(int)*size-1);
 for(int i = 0;i<size-1;i++){
         b[i]=a[i+1];
 }    
 int result=a[0];
 size--;
 a=b;
 return result;
}
void printqueue(){
     printf("\n");
     for(int i = 0;i<size;i++)
             printf("%d_",a[i]);
}
int main(){
 enqueue(10);
 enqueue(20);
 printf("\ndequeue -> %d",dequeue());
 enqueue(30);
 enqueue(40);
 printf("\ndequeue -> %d",dequeue());
 printf("\ndequeue -> %d",dequeue());
 printf("\ndequeue -> %d",dequeue());
 printf("\ndequeue -> %d",dequeue());
 getch();
 return 0;   
}
