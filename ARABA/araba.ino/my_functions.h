#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

//my_functions.h

	void komut_yolla( struct Kumanda  *komut ){
		strcpy( komut->tip, "move");
		komut->teker_sag=12;
		komut->teker_sol=-255;
		komut->kol_sag=70;
		komut->kol_sol=80;
		komut->sinyal_korna=0;
		komut->sinyal_lamba=1;

		sprintf(
		 	komut->cumle,
			"%s,%d,%d,%d,%d,%d,%d",
		 	komut->tip,
		 	komut->teker_sag,
			komut->teker_sol,
			komut->kol_sag,
			komut->kol_sol,
			komut->sinyal_korna,
			komut->sinyal_lamba
		 );
		 printf("\n Giden komut: \"%s\" \n" , komut->cumle);
	}

	void komut_al(  char cumle[32] ){
		 printf("\n Gelen komut: \"%s\"", cumle);
	}


void kumanda_oku(char gelen_komut[32]){
     char* token_hepsi,token_tip;
	 short* token_deger;

     token_hepsi=strtok(  gelen_komut  , "," );
     strcpy ( araba.tip , token_hepsi );

     token_hepsi= strtok( NULL, ",");
     araba.teker_sag =  atoi(token_hepsi);

     token_hepsi= strtok( NULL, ",");
     araba.teker_sol =   atoi(token_hepsi);

     token_hepsi= strtok( NULL, ",");
     araba.teker_sol =  atoi(token_hepsi);

     token_hepsi= strtok( NULL, ",");
     araba.kol_sag =  atoi(token_hepsi);

     token_hepsi= strtok( NULL, ",");
     araba.sinyal_korna = atoi(token_hepsi);

     token_hepsi= strtok( NULL, ",");
     araba.sinyal_lamba = atoi(token_hepsi);
}

void komut_parametlerini_yaz(){
     printf("\n araba komut tipi : %s \n" , araba.tip);
     printf("\n araba teker_sag : %d \n" , araba.teker_sag);
     printf("\n araba teker_sol : %d \n" , araba.teker_sol);
     printf("\n araba kol_sag : %d \n" ,araba.teker_sol);
     printf("\n araba kol_sag : %d \n" , araba.kol_sag);
     printf("\n araba sinyal_korna : %d \n" , araba.sinyal_korna);
     printf("\n araba sinyal_lamba : %d \n" , araba.sinyal_lamba);

}
#endif
