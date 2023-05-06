/* 1 milisaniye süre değerinde 
integer(sayı) tipinde değişken tanımladık */
int yanip_sonme_suresi = 1;    


void setup(){
  for( int  k=13;  k>=0 ; k--    ){  // 13 den 0 a kadar(0 dahil) eksilterek geriye say
      pinMode( k, OUTPUT );         //her pin numarasını çıkış olarak ayarla
  }
}

void loop(){
      /* 13 numaralı pine bağlı led den 0 a kadar yakıp söndürür */
      for(  int i= 13; i>=0 ; i--    ){ // 13 den 0 a kadar(0 dahil) eksilterek geriye say
        digitalWrite( i, HIGH );        // her pine HIGH (+5Volt gerilim ver)
        delay( yanip_sonme_suresi );    // en yukarıdaki sure kadar bekle
        digitalWrite(i , LOW );         // her pini LOW ( 0 Volt a indir )
        delay( yanip_sonme_suresi );    // en yukarıdaki sure kadar bekle
      }

      /* 0 numaralı pine bağlı led den 13 e kadar yakıp söndürür */
        for(  int i= 0; i<=13 ; i++    ){  // 0 dan 13 e kadar(13 dahil) arttırarak ileri  say
        digitalWrite( i, HIGH );      // her pine HIGH (+5Volt gerilim ver)
        delay( yanip_sonme_suresi );  // en yukarıdaki sure kadar bekle
        digitalWrite(i , LOW );       // her pini LOW ( 0 Volt a indir )
        delay( yanip_sonme_suresi );  // en yukarıdaki sure kadar bekle
      }
}
