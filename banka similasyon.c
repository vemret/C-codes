
//  Vahit Emre Tellier 2015010213031  Bil. müh. %100 ing.

#include<stdio.h>
#include"stdlib.h"
#include"string.h"
#include<time.h>
#include<string.h>
int z=0,toplambekleme=0;
//z kuyruga girdi cikitiyi kontrol ediyor!
struct gise{
	int topmus;
	int ortsure;
	int durum;
};
typedef struct gise gise;
struct musteri{
	int musteriId;
	int geliszamani;
	int islemsuresi;
};
 typedef struct musteri musteri;

struct queue{
	int mus;
	int beklmsuresi;
	struct queue *next;
};

typedef struct queue node;
node *head=NULL;
node *tail=NULL;
node *temp;

void enqueue(int deger){
	z++;
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->mus=deger;
		head->beklmsuresi=0;
		head->next=NULL;
		tail=head;
	}
	else{
		tail->next=(node*)malloc(sizeof(node));
		tail=tail->next;
		tail->mus=deger;
		tail->beklmsuresi=0;
		tail->next=NULL;
	}
}


int dequeue(){
		if(head==NULL){
		printf("queue zaten bos\n");
		}
		else{
			z--;
			int deger;
			temp=head;
			deger=head->mus;
			toplambekleme+=head->beklmsuresi;
			head=head->next;
			free(temp);
			return deger;
		}
}

int printqueue(){
	temp=head;
	int m;
	while(temp!=NULL){
		
		m++;	
		temp=temp->next;	
	}
	return m;
}

int islemsec(){
	
	int x,eft;
	
	x=rand()%3;
	x+=1;
	//printf("---y%d---",x);
	if(x==1){
		int eft;
		srand(time(NULL));
		eft=rand()%7;
		eft+=3;
		return eft;
	}
	else if(x==2){
		int kredi;
	
		kredi=rand()%10;
		kredi+=10;
		return kredi;
	}
	else if(x==3){
		int fatura;
	
		fatura=rand()%10;
		fatura+=2;
		return fatura;
	}
	else{
		int para;
	
		para=rand()%6;
		para+=1;
		return para;
	}
}
int musterigelmesuresi(){
	
	int x=rand()%5;
	//x+=1;
	//printf("x%d----",x);
	return x;
	
}

int main(){
	int zaman=1,zaman2,bekleyenmus=0,maxbek=0;
	gise gis1,gis2,gis3;
	gis1.durum=0;gis2.durum=0;gis3.durum=0;
	gis1.topmus=0;gis2.topmus=0;gis3.topmus=0;
	gis1.ortsure=0;gis2.ortsure=0;gis3.ortsure=0;
	srand(time(NULL));
	printf("lutfen similasyon suresini girin(dakika cinsinden):  ");
	int n,g=0,x,cnt=0,gis1cnt,gis2cnt,gis3cnt,no1,no2,no3,no11,no22,no33,t=0,m,y;
	int giscnt1,giscnt2,giscnt3,giscnt11,giscnt22,giscnt33;
	int g1zaman,g2zaman,g3zaman,g11zaman,g22zaman,g33zaman;
	musteri i,must,j;
	i.musteriId=1;
	scanf("%d",&n);
	node *temp1;
	int dizi[10000],c=0,u=0,o=0,p=0,w=0;
	while(zaman!=n){
			y=printqueue();
			if(cnt==0 && y<21){
			x=musterigelmesuresi();  
			x+=zaman;
			cnt++;
			
		}
			if(zaman==x && y<21){	
			enqueue(i.musteriId);
			
			m=printqueue();
			dizi[c]=m;
			c++;
			printf("%d.nci musteri %d.nci dakikada kuyruga girmistir.\n",(i.musteriId),zaman);
			i.musteriId++;
			cnt=0;
		}
		if(gis1.durum==0 && z>0){
			u++;
			no1=dequeue();
			must.islemsuresi=islemsec();
			gis1.ortsure=must.islemsuresi+gis1.ortsure;
			gis1cnt=must.islemsuresi;
			g1zaman=zaman;
			giscnt1=gis1cnt;
			gis1cnt+=zaman;
			gis1.topmus++;
			gis1.durum=1;
			bekleyenmus--;
			printf("%d.nci musteri %d.nci dakikada gise 1 e girmistir.\n",no1,zaman);
		}
		else if(gis1.durum==1){
			if(zaman==gis1cnt){
				gis1.durum=0;
				printf("%d.nci musteri %d.nci dakikada gise 1 den ayrildi.\n",no1,zaman);
			}
		}
		if(gis2.durum==0 && z>0){
			o++;
			no2=dequeue();
			must.islemsuresi=islemsec();
			gis2.ortsure=must.islemsuresi+gis2.ortsure;
			gis2cnt=must.islemsuresi;
			giscnt2=gis2cnt;
			g2zaman=zaman;
			gis2cnt+=zaman;
			gis2.topmus++;
			gis2.durum=1;
			bekleyenmus--;
			printf("%d.nci musteri %d.nci dakikada gise 2 ye girmistir.\n",no2,zaman);
		}
		else if(gis2.durum==1){
			if(zaman==gis2cnt){
				gis2.durum=0;
				printf("%d.nci musteri %d.nci dakikada gise 2 den ayrildi.\n",no2,zaman);
			}
		}
		if(gis3.durum==0 && z>0){
			p++;
			no3=dequeue();
			must.islemsuresi=islemsec();
			gis3.ortsure=must.islemsuresi+gis3.ortsure;
			gis3cnt=must.islemsuresi;
			giscnt3=gis3cnt;
			g3zaman=zaman;
			gis3cnt+=zaman;
			bekleyenmus--;
			gis3.topmus++;
			gis3.durum=1;
			printf("%d.nci musteri %d.nci dakikada gise 3 e girmistir.\n",no3,zaman);
		}
		else if(gis3.durum==1){
			if(zaman==gis3cnt){
				gis3.durum=0;
				printf("%d.nci musteri %d.nci dakikada gise 3 den ayrildi.\n",no3,zaman);
			}
		}
		if (zaman==(n-1)){
			//similasyon bitiminde kuyrukta kalan musterileri giseye sokuyor!
		//	printf("\n--giridi--")
			if(z>0){
				gis1.durum=0;gis2.durum=0;gis3.durum=0;
			//	printf("\n--girdi1----");
			while(z!=0){
				w++;
			//	printf("\n--girdi2----");
				zaman2++;
			if(gis1.durum==0 && z>0){
			u++;
			no11=dequeue();
			must.islemsuresi=islemsec();
			gis1.ortsure=must.islemsuresi+gis1.ortsure;
			gis1cnt=must.islemsuresi;
			giscnt11=gis1cnt;
			g11zaman=zaman2;
			gis1cnt+=zaman2;
			gis1.topmus++;
			gis1.durum=1;
			bekleyenmus--;
			printf("%d.nci musteri %d.nci dakikada gise 1 e girmistir.\n",no11,zaman2);
		}
		else if(gis1.durum==1){
			if(zaman2==gis1cnt){
				gis1.durum=0;
				printf("%d.nci musteri %d.nci dakikada gise 1 den ayrildi.\n",no11,zaman2);
			}
		}
		if(gis2.durum==0 && z>0){
			o++;
			no22=dequeue();
			must.islemsuresi=islemsec();
			gis2.ortsure=must.islemsuresi+gis2.ortsure;
			gis2cnt=must.islemsuresi;
			giscnt22=gis2cnt;
			g22zaman=zaman2;
			gis2cnt+=zaman2;
			gis2.topmus++;
			gis2.durum=1;
			bekleyenmus--;
			printf("%d.nci musteri %d.nci dakikada gise 2 ye girmistir.\n",no22,zaman2);
		}
		else if(gis2.durum==1){
			if(zaman2==gis2cnt){
				gis2.durum=0;
				printf("%d.nci musteri %d.nci dakikada gise 2 den ayrildi.\n",no22,zaman2);
			}
		}
		if(gis3.durum==0 && z>0){
			p++;
			no33=dequeue();
			must.islemsuresi=islemsec();
			gis3.ortsure=must.islemsuresi+gis3.ortsure;
			gis3cnt=must.islemsuresi;
			giscnt33=gis3cnt;
			g33zaman=zaman2;
			gis3cnt+=zaman2;
			bekleyenmus--;
			gis3.topmus++;
			gis3.durum=1;
			printf("%d.nci musteri %d.nci dakikada gise 3 e girmistir.\n",no33,zaman2);
		}
		else if(gis3.durum==1){
			if(zaman2==gis3cnt){
				gis3.durum=0;
				printf("%d.nci musteri %d.nci dakikada gise 3 den ayrildi.\n",no33,zaman2);
			}
		}
		temp1=head;
		while(temp1!=NULL){
		temp1->beklmsuresi++;
		if(temp1->beklmsuresi>maxbek){
			maxbek=temp1->beklmsuresi;
		} 
		temp1=temp1->next;
	}
			}
			//printf("\nkontrol---%d--%d--%d\n",no11,no22,no33);
		//	printf("\ngirdiiiii\n");
		}
	}
	temp1=head;
	while(temp1!=NULL){
		temp1->beklmsuresi++;
		if(temp1->beklmsuresi>maxbek){
			maxbek=temp1->beklmsuresi;
		} 
		temp1=temp1->next;
	}
		zaman2=zaman;
		zaman++;
	}
	int l,zaman3,zaman4,zaman33,zaman44;
	int temp[c];
	for(l=0;l<c;l++){
		temp[l]=dizi[l];
	}
	int max;
	max=temp[0];
	for(l=0;l<c;l++){
		if(temp[l]>max){
			max=temp[l];
			}
	}
//	printf("\n---%d--\n",no11);
//	printf("\n---%d--\n",giscnt1);
//	printf("\n--girdi%d--\n",w);
	if(w==0){
	//	printf("\n--girdi%d--\n",w);
		if(gis1.durum==1){
				zaman3=g1zaman;
				zaman3+=giscnt1;
				printf("%d.nci musteri %d.nci dakikada gise 1 den ayrildi.\n",no1,zaman3);
		}
		if(gis2.durum==1){
				zaman4=g2zaman;
				zaman4+=giscnt2;
				printf("%d.nci musteri %d.nci dakikada gise 2 den ayrildi.\n",no2,zaman4);
		}
		if(gis3.durum==1){
				g3zaman+=giscnt3;
				printf("%d.nci musteri %d.nci dakikada gise 3 den ayrildi.\n",no3,g3zaman);
		}
		
	}
	if(w!=0){
		// w similasyon bitiminden sonra giseye girdimi diye kontrol ediyor!
	//	printf("\n--girdi--\n");
	if(gis1.durum==1){
			zaman33=g11zaman;
			zaman33+=giscnt11;
				printf("%d.nci musteri %d.nci dakikada gise 1 den ayrildi.\n",no11,zaman33);
		}
		if(gis2.durum==1){
				zaman44=g22zaman;
				zaman44+=giscnt22;
				printf("%d.nci musteri %d.nci dakikada gise 2 den ayrildi.\n",no22,zaman44);
		}
		if(gis3.durum==1){
				g33zaman+=giscnt33;
				printf("%d.nci musteri %d.nci dakikada gise 3 den ayrildi.\n",no33,g33zaman);
		}
	}
	//c kuyruga giren kisi sayisi!
	if(c!=0){
		printf("\nherhagi bi zamanda kuyrukta en fazla bekleyen musteri sayisi %d",max);
	}
	else if(c==0){
		printf("\nhenuz kuyruga musteri girmedi.");
	}
	if(c!=0){
		printf("\nKuyrukta en uzun sure bekleyen musterinin bekleme suresi %d dk.",maxbek);
		printf("\nBir musterinin kuyrukta ortalama bekleme suresi %.2f dk.\n",(float)toplambekleme/c);
	}
	printf("\n1.gise  %d musteriye hizmet vermistir.",gis1.topmus);
	printf("\n2.gise  %d musteriye hizmet vermistir.",gis2.topmus);
	printf("\n3.gise  %d musteriye hizmet vermistir.\n",gis3.topmus);
	//u o p giseye girip girmedigini kontrol ediyor!
	if(u>0){
	printf("\n1.gise bir musteriye ortalama %d dk hizmet vermistir.",gis1.ortsure/gis1.topmus);
	}
	if(o>0){
	printf("\n2.gise bir musteriye ortalama %d dk hizmet vermistir.",gis2.ortsure/gis2.topmus);
	}
	if(p>0){
	printf("\n3.gise bir musteriye ortalama %d dk hizmet vermistir.",gis3.ortsure/gis3.topmus);
	}
	return 0;
}
