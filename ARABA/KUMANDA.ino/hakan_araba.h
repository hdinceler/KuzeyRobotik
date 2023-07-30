#ifndef HAKAN_ARABA_H
#define HAKAN_ARABA_H
char gelen_komut[32];
    struct Araba{
        char tip[8]; // en fazla 8 harfli tip . örnek: hareket , test, voltaj, raporver
        short teker_sag,teker_sol,kol_sag,kol_sol,sinyal_korna,sinyal_lamba;
        char cumle[32];
    };

struct Araba araba;

void kumanda_oku(char gelen_komut[32]){
     char* token;

     token=strtok(  gelen_komut  , "," );
     strcpy ( araba.tip , token );

     token= strtok( NULL, ",");
     araba.teker_sag =  atoi(token);

     token= strtok( NULL, ",");
     araba.teker_sol =   atoi(token);

     token= strtok( NULL, ",");
     araba.kol_sag =  atoi(token);

     token= strtok( NULL, ",");
     araba.kol_sol =  atoi(token);

     token= strtok( NULL, ",");
     araba.sinyal_korna = atoi(token);

     token= strtok( NULL, ",");
     araba.sinyal_lamba = atoi(token);
}
 
#endif

