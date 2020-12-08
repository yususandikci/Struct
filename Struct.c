#include <stdio.h>
#include <stdlib.h>



typedef struct et_struct{
    char etAdi[20];
    unsigned int etFiyat;
    char etTuru;
    char paketlemeTarih[11];
    char sonTuketimTarih[11];
    struct et_struct* sonraki;
}Et;

typedef struct tarim_urun_struct{
    char tarimAdi[20];
    unsigned int tarimFiyat;
    char tarimTuru;
    char alinmaTarih[11];
    struct tarim_urun_struct* sonraki;
}TarimUrun;

typedef struct sut_urun_struct{
    char sutAdi[20];
    unsigned int sutFiyat;
    char sonKullanmaTarih[11];
    struct sut_urun_struct* sonraki;
}SutUrun;

typedef struct konserve_urun_struct{
    char konserveAdi[20];
    unsigned int konserveFiyat;
    char sonKullanmaTarih[8];
    int reyonNumara;
    char reyonTaraf;
    struct konserve_urun_struct* sonraki;
}KonserveUrun;

typedef struct gidadisi_urun_struct{
    char urunAdi[20];
    unsigned int urunFiyat;
    char urunTuru;
    int reyonNumara;
    char reyonTaraf;
    struct gidadisi_urun_struct* sonraki;
}GidaDisiUrun;



Et* etListe=NULL;
TarimUrun* tarimListe=NULL;
SutUrun* sutListe=NULL;
KonserveUrun* konserveListe=NULL;
GidaDisiUrun* gidaDisiListe=NULL;



void urun_kaydet(char eklenecekUrunTipi){
    printf("\n");
    if(eklenecekUrunTipi == 'E' || eklenecekUrunTipi == 'e'){
        Et* yeniEt = (Et*)malloc(sizeof(Et));
        yeniEt->sonraki = NULL;

        printf("Urun Adini Giriniz: ");
        scanf("%20s",yeniEt->etAdi);
        printf("Urun Fiyatini Giriniz: ");
        scanf("%d",&yeniEt->etFiyat);
        getchar();
        printf("Et Turunu Giriniz (R-B-P): ");
        scanf("%c",&yeniEt->etTuru);
        printf("Paketleme Tarihini Giriniz (##-##-####): ");
        scanf("%s",yeniEt->paketlemeTarih);
        printf("Son Tuketim Tarihini Giriniz (##-##-####): ");
        scanf("%s",yeniEt->sonTuketimTarih);

        Et** tmp = &etListe;
        while((*tmp) != NULL) tmp = &(*tmp)->sonraki; 
        (*tmp) = yeniEt;

    }else if(eklenecekUrunTipi == 'T' || eklenecekUrunTipi == 't'){
        TarimUrun* yeniTarim = (TarimUrun*)malloc(sizeof(TarimUrun));
        yeniTarim->sonraki = NULL;

        printf("Urun Adini Giriniz: ");
        scanf("%20s",yeniTarim->tarimAdi);
        printf("Urun Fiyatini Giriniz: ");
        scanf("%d",&yeniTarim->tarimFiyat);
        getchar();
        printf("Tarim Turunu Giriniz (M-S): ");
        scanf("%c",&yeniTarim->tarimTuru);
        printf("Paketleme Tarihini Giriniz (##-##-####): ");
        scanf("%s",yeniTarim->alinmaTarih);

        TarimUrun** tmp = &tarimListe;
        while((*tmp) != NULL) tmp = &(*tmp)->sonraki; 
        (*tmp) = yeniTarim;

    }else if(eklenecekUrunTipi == 'S' || eklenecekUrunTipi == 's'){
        SutUrun* yeniSut = (SutUrun*)malloc(sizeof(SutUrun));
        yeniSut->sonraki = NULL;

        printf("Urun Adini Giriniz: ");
        scanf("%20s",yeniSut->sutAdi);
        printf("Urun Fiyatini Giriniz: ");
        scanf("%d",&yeniSut->sutFiyat);
        printf("Son Tuketim Tarihini Giriniz (##-##-####): ");
        scanf("%s",yeniSut->sonKullanmaTarih);

        SutUrun** tmp = &sutListe;
        while((*tmp) != NULL) tmp = &(*tmp)->sonraki; 
        (*tmp) = yeniSut;

    }else if(eklenecekUrunTipi == 'K' || eklenecekUrunTipi == 'k'){
        KonserveUrun* yeniKonserve = (KonserveUrun*)malloc(sizeof(KonserveUrun));
        yeniKonserve->sonraki = NULL;

        printf("Urun Adini Giriniz: ");
        scanf("%20s",yeniKonserve->konserveAdi);
        printf("Urun Fiyatini Giriniz: ");
        scanf("%d",&yeniKonserve->konserveFiyat);
        printf("Son Tuketim Tarihini Giriniz (##-####): ");
        scanf("%s",yeniKonserve->sonKullanmaTarih);
        printf("Reyon Numarasini Giriniz: ");
        scanf("%d",&yeniKonserve->reyonNumara);
        getchar();
        printf("Reyon Tarafini Giriniz (A-B): ");
        scanf("%c",&yeniKonserve->reyonTaraf);

        KonserveUrun** tmp = &konserveListe;
        while((*tmp) != NULL) tmp = &(*tmp)->sonraki; 
        (*tmp) = yeniKonserve;

    }else if(eklenecekUrunTipi == 'G' || eklenecekUrunTipi == 'g'){
        GidaDisiUrun* yeniGidaDisi = (GidaDisiUrun*)malloc(sizeof(GidaDisiUrun));
        yeniGidaDisi->sonraki = NULL;

        printf("Urun Adini Giriniz: ");
        scanf("%20s",yeniGidaDisi->urunAdi);
        printf("Urun Fiyatini Giriniz: ");
        scanf("%d",&yeniGidaDisi->urunFiyat);
        getchar();
        printf("Gida Disi Urun Turunu Giriniz (C-P-D): ");
        scanf("%c",&yeniGidaDisi->urunTuru);
        printf("Reyon Numarasini Giriniz: ");
        scanf("%d",&yeniGidaDisi->reyonNumara);
        getchar();
        printf("Reyon Tarafini Giriniz (A-B): ");
        scanf("%c",&yeniGidaDisi->reyonTaraf);


        GidaDisiUrun** tmp = &gidaDisiListe;
        while((*tmp) != NULL) tmp = &(*tmp)->sonraki; 
        (*tmp) = yeniGidaDisi;
        
    }else{
        printf("Hatali Urun Tipi.....\n");
    }
}

void urun_goster(){
    Et** etAdres = &etListe;
    TarimUrun** tarimAdres = &tarimListe;
    SutUrun** sutAdres = &sutListe;
    KonserveUrun** konserveAdres = &konserveListe;
    GidaDisiUrun** gidaDisiAdres = &gidaDisiListe;

    printf("\n------------------ Kayitli Urunler ------------------\n");
    while((*etAdres) != NULL){
        printf("%s %d %c %s %s\n",(*etAdres)->etAdi,(*etAdres)->etFiyat,(*etAdres)->etTuru,(*etAdres)->paketlemeTarih,(*etAdres)->sonTuketimTarih);
        etAdres = &(*etAdres)->sonraki; 
    }
    while((*tarimAdres) != NULL){
        printf("%s %d %c %s \n",(*tarimAdres)->tarimAdi,(*tarimAdres)->tarimFiyat,(*tarimAdres)->tarimTuru,(*tarimAdres)->alinmaTarih);
        tarimAdres = &(*tarimAdres)->sonraki;
    }
    while((*sutAdres) != NULL){
        printf("%s %d %s \n",(*sutAdres)->sutAdi,(*sutAdres)->sutFiyat,(*sutAdres)->sonKullanmaTarih);
        sutAdres = &(*sutAdres)->sonraki;
    }
    while((*konserveAdres) != NULL){
        printf("%s %d %s %d %c \n",(*konserveAdres)->konserveAdi,(*konserveAdres)->konserveFiyat,(*konserveAdres)->sonKullanmaTarih,(*konserveAdres)->reyonNumara,(*konserveAdres)->reyonTaraf);
        konserveAdres = &(*konserveAdres)->sonraki;
    }
    while((*gidaDisiAdres) != NULL){
        printf("%s %d %c %d %c \n",(*gidaDisiAdres)->urunAdi,(*gidaDisiAdres)->urunFiyat,(*gidaDisiAdres)->urunTuru,(*gidaDisiAdres)->reyonNumara,(*gidaDisiAdres)->reyonTaraf);
        gidaDisiAdres = &(*gidaDisiAdres)->sonraki;
    }
    printf("----------------------------------------------------\n\n");
}

void temizle(){
    Et** etAdres = &etListe;
    TarimUrun** tarimAdres = &tarimListe;
    SutUrun** sutAdres = &sutListe;
    KonserveUrun** konserveAdres = &konserveListe;
    GidaDisiUrun** gidaDisiAdres = &gidaDisiListe;

    while((*etAdres) != NULL){
        Et* tmp= (*etAdres);
        etAdres = &(*etAdres)->sonraki;
        free(tmp);
    }
    while((*tarimAdres) != NULL){
        TarimUrun* tmp= (*tarimAdres);
        tarimAdres = &(*tarimAdres)->sonraki;
        free(tmp);
    }
    while((*sutAdres) != NULL){
        SutUrun* tmp= (*sutAdres);
        sutAdres = &(*sutAdres)->sonraki;
        free(tmp);
    }
    while((*konserveAdres) != NULL){
        KonserveUrun* tmp= (*konserveAdres);
        konserveAdres = &(*konserveAdres)->sonraki;
        free(tmp);
    }
    while((*gidaDisiAdres) != NULL){
        GidaDisiUrun* tmp= (*gidaDisiAdres);
        gidaDisiAdres = &(*gidaDisiAdres)->sonraki;
        free(tmp);
    }
}



int main(){
    int secim=0;
    char secimTur;
    while(1){
        printf("1. Urun Ekle\n");
        printf("2. Urunleri Listele\n");
        printf("3. Cikis\n\n");
        printf("Secim Yapiniz (1-3 arasi): ");
        scanf("%d",&secim);
        getchar();

        if(secim==1){
            printf("Urun Katogorisi Seciniz (E,T,S,K,G): ");
            scanf("%c",&secimTur);
            urun_kaydet(secimTur);
            system("pause");
        }else if(secim==2){
            urun_goster();
            system("pause");
        }else if(secim==3){
            break;
        }else{
            printf("Hatali Secim Yapildi....\n\n");
            system("pause");
        }
        system("cls");
    }

    temizle();
    system("pause");
    return 0;
}