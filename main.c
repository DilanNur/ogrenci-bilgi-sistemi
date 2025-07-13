#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char isimler[100][20];
int numaralar[100];
float ortalamalar[100];
int ogrenciSayisi=0;


void ogrenciEkle();
void ogrenciListele();
int  ogrenciAra();
void cikisYap();


int main()
{
    while (1){
    int secim;
    printf("\n\n----------- OBS Sistemine Hosgeldiniz ------------\n");
    printf("\n\nAsagidaki seceneklerden birini seciniz!\n\n");
    printf("1-Ogrenci Ekleme\n2-Tum ogrencileri listele\n3-Ogrenci Ara(numaraya gore)\n4-Cikis\n");
    printf("\nSeciminiz:");
    scanf("%d",&secim);

    switch(secim){

    case 1:
        ogrenciEkle();
        break;
    case 2:
        ogrenciListele();
        break;
    case 3:
        ogrenciAra();
        break;
    case 4:
        cikisYap();
        break ;
    default:
    printf("\nYanlis bir secim yaptiniz.Lutfen sadece bu seceneklerden secim yapiniz!\n");

    }
  }
    return 0;
}

void ogrenciEkle()
{
    float vizeNot,finalNot,notOrt=0;
    char isim[20];
    int numara;

    printf("\nEklemek istediginiz ogrencinin ismini ve numarasini  giriniz:");
    scanf("\n%s %d",isim,&numara);

    printf("\n%s ogrencinin vize ve final notlarini sirasiyla giriniz:",isim);
    scanf("%f %f",&vizeNot,&finalNot);

    notOrt=vizeNot*0.40 + finalNot*0.60;
    printf("\nNot ortalamasi %f",notOrt);
    printf("\n\n%s isimli ogrencinin vizesi %f , finali %f ve not ortalamasi %f\n",isim,vizeNot,finalNot,notOrt);

   if (80<=notOrt && notOrt<=100)
   {
    printf("\nTebrikler AA ile gectiniz!\n");

   }else if (71<=notOrt && notOrt<=80)
   {
    printf("\nTebrikler BA ile gectiniz!\n");
   }
   else if (63<=notOrt && notOrt<=71)
   {
    printf("\nTebrikler BB ile gectiniz!\n");
   }
   else if (55<=notOrt && notOrt<=63)
   {
    printf("\nTebrikler CB ile gectiniz!\n");
   }
   else if (50<=notOrt && notOrt<=55)
   {
    printf("\nTebrikler CC ile gectiniz!\n");
   }
   else if (45<=notOrt && notOrt<=50)
   {
    printf("\nTebrikler DC ile gectiniz!\n");
   }
   else if (35<=notOrt && notOrt<=45)
   {
    printf("\nTebrikler DD ile gectiniz!\n");
   }
   if (0<=notOrt && notOrt<=35)
   {
    printf("\nMaalesef FF ile kaldiniz!");
   }

   strcpy(isimler[ogrenciSayisi], isim);
   numaralar[ogrenciSayisi] = numara;
   ortalamalar[ogrenciSayisi] = notOrt;
   ogrenciSayisi++;  // bir öðrenci daha eklendi

}
void ogrenciListele()
{
  int i;
  if(ogrenciSayisi==0){
    printf("\nHenuz hicbir ogrenci eklenmedi.");
    return;
  }
  printf("\n\n-------Tum ogrenci bilgileri--------");
  for(i=0;i<ogrenciSayisi;i++){
    printf("\n%d. ogrenci",i+1);
    printf("\nIsim:%s",isimler[i]);
    printf("\nNumara:%d",numaralar[i]);
    printf("\nNot ortalamasi:%.2f",ortalamalar[i]);
  }
}

int  ogrenciAra()
{
    int arananNumara,i,bulundu=0;
    printf("\nAramak istediginiz ogrencinin numarasini giriniz:");
    scanf("%d",&arananNumara);

    for(i=0;i<ogrenciSayisi;i++){
        if(numaralar[i]==arananNumara){
            printf("\nAranan ogrenci bulundu");
            printf("\nIsmi %s , numarasi %d , not ortalamasi %.2f\n",isimler[i],numaralar[i],ortalamalar[i]);
            bulundu=1;
            break;
        }
        }
        if(!bulundu){

        printf("\nBu numaraya sahip aradiginiz ogrenci  bulunamadi!");


    }

    return 0;
}

void cikisYap()
{

    printf("\nCikis yapiliyor...\n");
    exit(0);
}
