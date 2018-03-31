#include<stdio.h>
int main(){
	int a[6]={1,9,2,7,3,6},temp;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(int i=0;i<6;i++){
	printf("%d",a[i]);
}
}
