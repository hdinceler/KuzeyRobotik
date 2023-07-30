#ifndef HAKAN_BISIKLET_H
#define HAKAN_BISIKLET_H
    
    #include "buzzer.h"
    
    bool bayrak_hall=false;
    bool hall_aktif=false;
    bool hall_pasif=false;
    float mesafe=0.0;
    float mesafe_buff=0.0;
    int kilometre=0;
    int metre=0;
    char ekran_kilometre[5];
    char ekran_metre[5];
    char ekran_hiz[3];
    unsigned long int  sayac=0;
    unsigned long int tur_zamani=0;
    unsigned long int baslangic_zamani=0;
    float hiz=0.0;

    //lcd için dolu kutu karakteri
    byte dolu_kutu[] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
    };

    bool zaman_say(unsigned int zaman_say_interval  ) {
        unsigned long currentTime = millis();
        // İki sinyal arasındaki süreyi kontrol et
        if (currentTime - zaman_say_previousTime >= zaman_say_interval) {
            zaman_say_previousTime = currentTime; // Sonraki sinyal için süre sayacını sıfırla
            return true;
        }
        return false;
    }


    void sesli_uyari(unsigned int milisaniye){
        if(  zaman_say(milisaniye) ) tone(buzzer_pin ,1000,100);
        else noTone(buzzer_pin);
         lcd.backlight() ;

    }

    void sesli_isikli_uyari(unsigned int milisaniye){
        
        if(  zaman_say(milisaniye) )  {
            lcd.backlight() ;
            tone(buzzer_pin ,1000,100);
        }
        else {
            lcd.noBacklight();
            noTone(buzzer_pin);
        }
        // lcd.backlight();
    }

    void ilerleme_kutulari(int anlik_hiz){
        ///1000 ms hall sensöründen sinyal gelmezse hızı sıfır göster 
        // ekran ışığını kapat ve ses çal
         if(anlik_hiz==0 ){
           lcd.setCursor(1,1);
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
        //    buzzer_intro();
        //    lcd.noBacklight();
            //sesli_uyari(1000);
        }
        if(anlik_hiz>0 && anlik_hiz<=10 ){
           lcd.setCursor(1,1);
           lcd.write(byte(0));
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
       sesli_uyari(500);
        }
        if(anlik_hiz>10 && anlik_hiz<=30 ){
           lcd.setCursor(1,1);
           lcd.write(byte(0));
           lcd.write(byte(0));
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
       sesli_uyari(250);
        }
        if(anlik_hiz>40 && anlik_hiz<=50 ){
            lcd.setCursor(1,1);
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
            sesli_uyari(150);
        }
         
        if(anlik_hiz>50 && anlik_hiz<=60 ){
            lcd.setCursor(1,1);
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
           lcd.print(" ");
           lcd.print(" ");
           lcd.print(" ");
            sesli_uyari(100);
        }
        if(anlik_hiz>60 && anlik_hiz<=70 ){
            lcd.setCursor(1,1);
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
           lcd.print(" ");
           lcd.print(" ");
            sesli_uyari(50);
        }
        if(anlik_hiz>70 && anlik_hiz<=80 ){
            lcd.setCursor(1,1);
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
           lcd.print(" ");
            sesli_uyari(30);
        }        
        if(anlik_hiz>80){
            lcd.setCursor(1,1);
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            lcd.write(byte(0));
            sesli_isikli_uyari(20);
        }                
    }



    void hesapla_mesafe(){
        mesafe=(teker_cevresi * (float)sayac) / 1000;
        kilometre=(int)mesafe;
        mesafe_buff = mesafe *  1000  ;
        metre= (int)mesafe_buff % 1000;

        sprintf( ekran_kilometre , "%04d", kilometre );
        Serial.print("\n km:");
        Serial.print( ekran_kilometre );
        Serial.print("\n");

        sprintf( ekran_metre , "%03d",metre );  
        Serial.print("\n m:");
        Serial.print( ekran_metre );
        Serial.print("\n");

    }

    void hesapla_hiz(){
        Serial.print("\n tur zamani:");
        Serial.print(tur_zamani);
        Serial.print("ms\n");
        hiz=  ( teker_cevresi / 1000.0  ) / ( tur_zamani / 3600000.0 );
        float zaman_s = tur_zamani / 1000.0;
        float zaman_h = tur_zamani / 360000.0;
     
        sprintf( ekran_hiz , "%3d" , (int)hiz  );
        Serial.print("\n hiz:");
        Serial.print( ekran_hiz );
        Serial.print("\n");
        
    }

 

    void say(){
        int sensorStatus = digitalRead(hall_pin);
        hall_aktif= ( sensorStatus ==0 &&  bayrak_hall==false  );
        hall_pasif=( sensorStatus== 1 && bayrak_hall ==true );
        if(hall_aktif){
            sayac++;
            // hesapla_mesafe();
            tur_zamani=millis()-baslangic_zamani;
            // hesapla_hiz();
            bayrak_hall=true; 
              ilerleme_kutulari( (int)hiz );

            }
        if(hall_pasif){ 
            bayrak_hall=false;
            baslangic_zamani=millis();
            }
        lcd.setCursor(0,0); lcd.print(ekran_kilometre);
        lcd.setCursor(6,0); lcd.print("km");
        lcd.setCursor(10,0); lcd.print(ekran_metre);
        lcd.setCursor(14,0); lcd.print("m");
       
        

        //okunması için gösterimi yavaşlat
        if( zaman_say(300) ){lcd.setCursor(9,1); lcd.print(ekran_hiz);}
        lcd.setCursor(13,1); lcd.print("kmh");
      
      
         

    }


    void lcd_intro(uint8_t sure){
        
        lcd.setCursor(0,0);
        lcd.print("KUZEYROBOTiK.COM");
        giris_muzigi();

        short i=0;
        short i_baglaniyor;
    while(1){
        lcd.setCursor(0,0);
        delay(50);
        lcd.print("   BASLIYOR...  ");
        delay(300);
        for( i_baglaniyor=0;i_baglaniyor<=16;i_baglaniyor++){
            lcd.setCursor(i_baglaniyor,0);
            lcd.print(".");
            lcd.setCursor(i_baglaniyor,1);
            lcd.print(" ");
            delay(20+i_baglaniyor*sure);
            Serial.println("1:"+i_baglaniyor);
        }
        for(i_baglaniyor=16;i_baglaniyor>=0;i_baglaniyor--){
            lcd.setCursor(i_baglaniyor,0);
            lcd.print(" ");
            lcd.setCursor(i_baglaniyor,1);
            lcd.print(".");
            delay(10+i_baglaniyor*sure);
            Serial.println("2:"+i_baglaniyor);
        }
        i++;
        if(i==2) break;
    }
        lcd.setCursor(0,0);
        lcd.print("Sistem Hazir");
        lcd.setCursor(0,1);
        lcd.print("Haydi Gezelim :)");
        delay(1000);
        buzzer_intro();
        lcd.clear();

    }






#endif