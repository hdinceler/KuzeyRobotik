#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "hakan_araba.h"

int main(){
	komut_yolla(&kumanda);	 // kumanda ismiyle olu�turulan Kumanda struct �n�n adresini fonksiyona yolluyoruz. o da pointer ile yakal�yor
 	char gelen_komut[32];
 	strcpy(gelen_komut ,kumanda.cumle );

    kumanda_oku(gelen_komut);
    komut_parametlerini_yaz();

   printf( "\n ====================================== \n" );
   return 0;
}
