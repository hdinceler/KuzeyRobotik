// #include <Arduino.h>
// int hall_pin = 2;  // 2 nolu pine taktık, istediğinize takabilirsiniz ;(0-1 hariç)
// bool bayrak=false;
// bool hall_aktif=false;
// bool hall_pasif=false;
// float teker_cevresi=1.86;  // m cinsinden örneğin 186cm ise => 1.86 yazılacak
// float mesafe=0.0;
// float mesafe_buff=0.0;
// int kilometre=0;
// int metre=0;
// char ekran_kilometre[5];
// char ekran_metre[5];
// char ekran_hiz[5];
// unsigned long int  sayac=0;
// unsigned long int tur_zamani=0;
// unsigned long int baslangic_zamani=0;
// float hiz=0.0;

// void say();
// void setup() {
//   pinMode(hall_pin, INPUT_PULLUP);
//   Serial.begin(9600);
// }
// void hesapla_hiz(){
//   Serial.print("\n tur zamani:");
//   Serial.print(tur_zamani);
//   Serial.print("ms\n");
//   hiz=  ( teker_cevresi / 1000.0  ) / ( tur_zamani / 3600000.0 );

//   float zaman_s = tur_zamani / 1000.0;
//   float zaman_h = tur_zamani / 360000.0;
//   sprintf( ekran_hiz , "%02dkm/h" , (int)hiz  );
//   Serial.print("\n Zaman::");
//   Serial.print(zaman_s);
//   Serial.print("sn, :");
//   Serial.print(zaman_h);
//   Serial.print("h, HIZ: :");
//   Serial.print(hiz);
//   Serial.print(" km/h, ekran_hiz:");
//   Serial.print(ekran_hiz);

// }
// void hesapla_mesafe(){
//   mesafe=(teker_cevresi * (float)sayac) / 1000;
//   kilometre=(int)mesafe;
//   mesafe_buff = mesafe *  1000  ;
//   metre= (int) mesafe_buff % 1000;
//   sprintf( ekran_kilometre , "%04d", kilometre );
//   sprintf( ekran_metre , "%04d", metre );

//     Serial.print("\n Mesafe:");
//     Serial.print(mesafe);
//     Serial.print("m,:");
//     Serial.print(kilometre);
//     Serial.print("km, :");
//     Serial.print("metre, :");
    
//   }
// void say(){
//   int sensorStatus = digitalRead(hall_pin);
//   hall_aktif= ( sensorStatus ==0 &&  bayrak==false  );
//   hall_pasif=( sensorStatus== 1 && bayrak ==true );
//   if(hall_aktif){
//       sayac++;
//       hesapla_mesafe();
//       tur_zamani=millis()-baslangic_zamani;
//       hesapla_hiz();
//       bayrak=true; }
//   if(hall_pasif){ 
//       bayrak=false;
//       baslangic_zamani=millis();
//     }
// }

// void loop() {
//   say();
// }

