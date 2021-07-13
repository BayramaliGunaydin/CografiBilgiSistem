#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sehir{
    int plaka;
    char sehir[20];
    char bolge[2];
    int komsusayisi;
    struct sehir *sonraki;
    struct sehir *onceki;
    struct komsu *komsu;
};
struct komsu{
    int plaka;
    char komsuismi[20][20];
    char bolge[2];
    struct komsu *sonraki;
};
struct sehir *ilk=NULL , *son=NULL;
struct komsu *ilk1=NULL , *son1=NULL;
void sonaekle(int plaka, char sehir[],char bolge[]){
    struct sehir *yenisehir=(struct sehir*) malloc(sizeof(struct sehir));
    yenisehir->plaka=plaka;
    strcpy(yenisehir->bolge,bolge);
    strcpy(yenisehir->sehir,sehir);
    if(ilk==NULL){
    ilk=yenisehir;
    son=yenisehir;
    ilk->komsu=NULL;
    yenisehir->sonraki=NULL;
    yenisehir->onceki=NULL;
    }
    else{
        son->sonraki=yenisehir;
        yenisehir->onceki=son;
        yenisehir->sonraki=NULL;
        son=yenisehir;
    }
    son1=yenisehir;
    ilk1=yenisehir;
    ilk1->sonraki=NULL;
    son1->sonraki=NULL;
    yenisehir->komsu=NULL;
}
void basaekle(int plaka,char sehir[],char bolge[]){
   struct sehir *yenisehir=(struct sehir*) malloc(sizeof(struct sehir));
     yenisehir->plaka=plaka;
    strcpy(yenisehir->bolge,bolge);
    strcpy(yenisehir->sehir,sehir);
    if(ilk==NULL){
    ilk=yenisehir;
    son=yenisehir;
    ilk->komsu=NULL;
    yenisehir->sonraki=NULL;
    yenisehir->onceki=NULL;
    yenisehir->komsu=NULL;}
   else{
    yenisehir->sonraki=ilk;
    yenisehir->onceki=NULL;
    ilk->onceki=yenisehir;
    ilk=yenisehir;}
}
void sehirekle(int plaka, char sehir[],char bolge[]){
struct sehir *yenisehir=(struct sehir*) malloc(sizeof(struct sehir));
struct sehir *liste=ilk;
struct komsu *liste2=liste->komsu;
struct sehir *temp;
int sayac=0;
strcpy(yenisehir->sehir,sehir);
    yenisehir->plaka=plaka;
    strcpy(yenisehir->bolge,bolge);
    while(liste->sonraki!=NULL){
  if(liste->plaka==yenisehir->plaka){
    printf("Girdiginiz plakada sehir bulunmakta.");sayac++;
    break;
  }liste=liste->sonraki;}
  liste=ilk;
if(sayac==0){
while(liste->sonraki!=NULL){
    if(liste==NULL){
    ilk=yenisehir;
    son=yenisehir;
    ilk->komsu=NULL;
    yenisehir->sonraki=NULL;
    yenisehir->onceki=NULL;
    yenisehir->komsu=NULL;
     break;
    }
    else if(ilk->plaka>yenisehir->plaka){
    yenisehir->sonraki=ilk;
    yenisehir->onceki=NULL;
    yenisehir->komsu=NULL;
    ilk->onceki=yenisehir;
    ilk=yenisehir;

    break;
    }
    else if(son->plaka<yenisehir->plaka){
        son->sonraki=yenisehir;
        yenisehir->onceki=son;
        yenisehir->sonraki=NULL;
        yenisehir->komsu=NULL;
        son=yenisehir;
    break;
    }

    else if(liste->plaka<yenisehir->plaka && liste->sonraki->plaka>yenisehir->plaka){
    liste->sonraki->onceki=yenisehir;
    temp=liste->sonraki;
    liste->sonraki=yenisehir;
    yenisehir->onceki=liste;
    yenisehir->sonraki=temp;
    yenisehir->komsu=NULL;
    break;
    }
    printf("saddsa");
    liste=liste->sonraki;
}}




}
void komsuekle(char sehir[],int plaka){
    struct komsu *yenikomsu=(struct komsu*) malloc(sizeof(struct komsu));
        strcpy(yenikomsu->komsuismi,sehir);
        yenikomsu->plaka=plaka;
    if(son->komsu==NULL){
        son->komsu=yenikomsu;
        son1=yenikomsu;
        yenikomsu->sonraki=NULL;
    }
    else{
        son1->sonraki=yenikomsu;
        son1=yenikomsu;
        yenikomsu->sonraki=NULL;
    }
}
void sehirsil(int plaka){
    struct sehir *sil=ilk;
struct sehir *liste=ilk;
struct komsu *liste2=liste->komsu;

while(liste->sonraki!=NULL){
    if(sil->plaka==plaka)break;
    else{sil=sil->sonraki;}
}  if(sil==ilk)
{
    sil->sonraki->onceki=NULL;
     ilk=ilk->sonraki;}
     else if(sil==son){
        sil->onceki->sonraki=NULL;
        sil->sonraki=NULL;
        sil->onceki=NULL;
        son=son->onceki;
     }
    else {sil->onceki->sonraki=sil->sonraki;
    sil->sonraki->onceki=sil->onceki;}
    free(sil);
}
void Listele(){
    struct sehir *liste=ilk;
struct komsu *liste2=liste->komsu;

while(liste->sonraki!=NULL)
{
printf("%d,",liste->plaka);
printf("%s,",liste->bolge);
printf("%s,",liste->sehir);
liste2=liste->komsu;
if(liste2!=NULL){
while(liste2->sonraki!=NULL){
    printf("(%d,",liste2->plaka);
    printf("%s)",liste2->komsuismi);
liste2=liste2->sonraki;
}
printf("(%d,",liste2->plaka);
printf("%s)",liste2->komsuismi);
    }
printf("\n");
liste=liste->sonraki;
}
printf("%d,",liste->plaka);
printf("%s,",liste->bolge);
printf("%s,",liste->sehir);
liste2=liste->komsu;
if(liste2!=NULL){
while(liste2->sonraki!=NULL){
    printf("(%d,",liste2->plaka);
    printf("%s)",liste2->komsuismi);
liste2=liste2->sonraki;
}printf("(%d,",liste2->plaka);
    printf("%s)",liste2->komsuismi);}
}
void komsubul(int a,int b){
struct sehir *liste=ilk;
struct komsu *liste2=liste->komsu;
int i,x=0;
while(liste->sonraki!=NULL){
    liste2=liste->komsu;
    i=1;
if(liste2!=NULL){
while(liste2->sonraki!=NULL){
liste2=liste2->sonraki;
i++;
}
    if(i>a&&i<b){
            x++;
            printf("%d,",liste->plaka);
printf("%s,",liste->bolge);
printf("%s,",liste->sehir);
printf("komsu sayisi:%d\n",i);
    }
    if(i==a&&i==b){
            x++;
printf("%d,",liste->plaka);
printf("%s,",liste->bolge);
printf("%s",liste->sehir);
printf("komsu sayisi:%d\n",i);
    }
}
liste=liste->sonraki;

}
if(x==0){

    printf("Girdiginiz sayida komsusu olan il yoktur.");

}}
void komsusirala(){
int i,j;
struct sehir *liste=son;
struct komsu *liste2=liste->komsu;
int tmp;
char tmp2[20];

while(liste2->sonraki!=NULL){

        if(liste2->plaka>liste2->sonraki->plaka)
        {
          tmp=liste2->plaka;
          liste2->plaka=liste2->sonraki->plaka;
          liste2->sonraki->plaka=tmp;
          strcpy(tmp2,liste2->komsuismi);
          strcpy(liste2->komsuismi,liste2->sonraki->komsuismi);
          strcpy(liste2->sonraki->komsuismi,tmp2);
        }
        liste2=liste2->sonraki;
}

}
void bolgebilgisi(char bolge[]){
struct sehir *liste=ilk;
struct komsu *liste2=liste->komsu;
int i,x=0;
printf("%s bolgesindeki sehir bilgileri:\n",bolge);
while(liste->sonraki!=NULL){
    if(bolge[0]==liste->bolge[0]&&bolge[1]==liste->bolge[1]){
    x++;
        printf("%d,",liste->plaka);
        printf("%s,",liste->bolge);
        printf("%s,",liste->sehir);
        i=1;
        liste2=liste->komsu;
if(liste2->sonraki!=NULL){
while(liste2->sonraki!=NULL){
liste2=liste2->sonraki;
i++;
}
    }
printf("komsu sayisi:%d\n",i);
}


liste=liste->sonraki;


}
if(x==0){

    printf("Girdiginiz kodlama ile bolge bulanmamaktadir.");
}

}
void plakaarama(int plaka){
struct sehir *liste=ilk;
struct komsu *liste2=liste->komsu;
int i;
while(liste->sonraki!=NULL){
   i=0;
   liste2=liste->komsu;
   while(liste2->sonraki!=NULL){
liste2=liste2->sonraki;
i++;
    }
   if(liste->plaka==plaka){
printf("%d,",liste->plaka);
printf("%s,",liste->bolge);
printf("%s,",liste->sehir);
printf("Komsu sayisi:%d",i);
liste2=liste->komsu;

if(liste2->sonraki!=NULL){
while(liste2->sonraki!=NULL){
    printf("(%d,",liste2->plaka);
    printf("%s)",liste2->komsuismi);
liste2=liste2->sonraki;
i++;
    }

}
}liste=liste->sonraki;
}}
void bonus(int a,int b){
struct sehir *liste=ilk;
struct sehir *liste3=ilk;
struct komsu *liste2=liste->komsu;
struct komsu *liste4=liste3->komsu;
struct komsu *liste5=liste->komsu;
int i,x=0;
int komplaka;
while(liste->sonraki!=NULL){
    liste2=liste->komsu;
    i=0;
if(liste2->sonraki!=NULL){
while(liste2->sonraki!=NULL){
liste2=liste2->sonraki;
i++;
}
    if(i>a&&i<b){
liste5=liste->komsu;
liste4=liste3->komsu;
liste3=ilk;
komplaka=liste5->plaka;
while(liste5!=NULL){x++;
        liste3=ilk;
while(liste3->sonraki!=NULL){
        liste4=liste3->komsu;
        while(liste4!=NULL){
            if(komplaka==liste4->plaka){
                if(liste3->sehir!=liste->sehir){
                printf("hem %s ye hemde %s ye komsu olan sehir:%s\n",liste3->sehir,liste->sehir,liste4->komsuismi);
                break;}
            }

            liste4=liste4->sonraki;

        }

liste3=liste3->sonraki;}
komplaka=liste5->plaka;
liste5=liste5->sonraki;
}
    }
}
liste=liste->sonraki;
}
if(x==0){

    printf("Girdiginiz sayida bilgi bulunamadi.");

}


}
int main(){
    struct sehir *sehirler;
    struct komsu *komsular;
    char buf[100];
    FILE *dosya,*dosya2;
    dosya=fopen("C:\\Users\\lem_l\\OneDrive\\Masaüstü\\sehirler\\sehirler.txt","r");
    dosya2=fopen("C:\\Users\\lem_l\\OneDrive\\Masaüstü\\sehirler\\cikti.txt","w");
  komsular=(struct komsu*)malloc(5000000*sizeof(komsular));
  sehirler=(struct sehir*)malloc(500000*sizeof(sehirler));
   int k=0,a,b;
   int i=0;
   int j=0,w;
   int sehirsayisi=0;
   int secim;
   int komsusay;
    char *token;
   while(!feof(dosya)){

    fgets(buf,100,dosya);
    token=strtok(buf,",\n");
    sehirler[k].plaka=atoi(token);
    token=strtok(NULL,",\n");
    strcpy(sehirler[k].sehir,token);
    token=strtok(NULL,",\n");
    strcpy(sehirler[k].bolge,token);
    token=strtok(NULL,",\n");
    j=0;
    sehirler[k].komsusayisi=0;sehirsayisi++;
    while(token!=NULL){
        strcpy(komsular[i].komsuismi[j],token);
        token=strtok(NULL,",\n");
        sehirler[k].komsusayisi++;
        j++;
    }
    k++;i++;
   }


int x=0;
           for(j=0;j<sehirsayisi;j++){
                    for(k=0;k<sehirler[j].komsusayisi;k++){
                        for(i=0;i<sehirsayisi;i++){
                            if(komsular[j].komsuismi[k][0]==sehirler[i].sehir[0]&&komsular[j].komsuismi[k][1]==sehirler[i].sehir[1]&&komsular[j].komsuismi[k][2]==sehirler[i].sehir[2]&&komsular[j].komsuismi[k][3]==sehirler[i].sehir[3]&&komsular[j].komsuismi[k][4]==sehirler[i].sehir[4]){
                                komsular[x].plaka=sehirler[i].plaka;x++;
                                break;
                            }
                        }
                    }
            }
            x=0;
     for(i=0;i<sehirsayisi;i++){
            sonaekle(sehirler[i].plaka,sehirler[i].sehir,sehirler[i].bolge);
            for(k=0;k<sehirler[i].komsusayisi;k++){
                  komsuekle(komsular[i].komsuismi[k],komsular[x].plaka);
                  x++;
                  for(j=0;j<sehirler[i].komsusayisi+20;j++){
                  komsusirala();}
            }


            }

char sehiradi[20],sehirbolge[2],sehiradi1[10];
            while(1){
printf("\n--------Menu----------\n");
printf("1:Son sehirler bilgisini yazdir\n");
printf("2:Sehir ekle\n");
printf("3:Sehir sil\n");
printf("4:Bolge bilgisi iste\n");
printf("5:Verilen komsu sayisina uyan sehirleri bul\n");
printf("6:Sehir arama\n");
printf("7:Son sehir bilgisi listesini goster\n");
printf("8:Bonus\n");
struct sehir *liste=ilk;
struct komsu *liste2=liste->komsu;
scanf("%d",&secim);
switch(secim){

case 1:

while(liste->sonraki!=NULL)
{
fprintf(dosya2,"%d,",liste->plaka);
fprintf(dosya2,"%s,",liste->bolge);
fprintf(dosya2,"%s,",liste->sehir);
liste2=liste->komsu;
if(liste2!=NULL){
while(liste2->sonraki!=NULL){
    fprintf(dosya2,"---->(%d,",liste2->plaka);
    fprintf(dosya2,"%s,)",liste2->komsuismi);
liste2=liste2->sonraki;
}
fprintf(dosya2,"---->(%d,",liste2->plaka);
    fprintf(dosya2,"%s)",liste2->komsuismi);}
fprintf(dosya2,"\n\t^|\n\t||\n\t||\n\t|v\n");
liste=liste->sonraki;

}
fprintf(dosya2,"%d,",liste->plaka);
fprintf(dosya2,"%s,",liste->bolge);
fprintf(dosya2,"%s,",liste->sehir);
liste2=liste->komsu;
if(liste2!=NULL){
while(liste2->sonraki!=NULL){
    fprintf(dosya2,"---->(%d,",liste2->plaka);
    fprintf(dosya2,"%s,)",liste2->komsuismi);
liste2=liste2->sonraki;
}
fprintf(dosya2,"---->(%d,",liste2->plaka);
    fprintf(dosya2,"%s)",liste2->komsuismi);}printf("sehirler.txt yazdirildi");
break;
case 2:

printf("Eklenecek sehirin plakasi:");
scanf("%d",&a);
printf("Eklenecek sehirin adi:");
scanf("%s",sehiradi1);
printf("Eklenecek sehirin bolgesi:");
scanf("%s",sehirbolge);
printf("Eklenecek sehirin komsu sayisi:");
scanf("%d",&komsusay);
sehirekle(a, sehiradi1, sehirbolge);
for(i=0;i<komsusay;i++){
    printf("Eklenecek komsunun plakasi:");
scanf("%d",&a);
printf("Eklenecek komsunun adi:");
scanf("%s",sehiradi);
komsuekle(sehiradi,a);
}
break;
case 3:
   printf("silmek istedigin plakayi gir:");
   scanf("%d",&a);
   sehirsil(a);
    break;
    case 4:
    printf("Bilgisini ogrenmek istediginiz bolgeyi giriniz(Bolgelerin kisa kodlamalarini giriniz):");
    scanf("%s",sehirbolge);
    bolgebilgisi(sehirbolge);
    break;
    case 5:
        printf("En az kac komsu?");
        scanf("%d",&a);
        printf("En fazla kac komsu?");
        scanf("%d",&b);
        komsubul(a,b);
        break;
    case 6:
      printf("Aramak istediginiz sehirin plaka kodunu giriniz:");
      scanf("%d",&a);
      plakaarama(a);

        break;
    case 7:
        Listele();
        break;
        case 8:
            printf("En az komsu sayisi?");
            scanf("%d",&a);
            printf("En fazla komsu sayisi?");
            scanf("%d",&b);
            bonus(a,b);
            break;
fclose(dosya);
fclose(dosya2);
default:
    return 0;}}
    return 0;
}
