#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
float teker_cevresi=1.86;  // m cinsinden örneğin 186cm ise => 1.86 yazılacak
int hall_pin = 2;  // 2 nolu pine taktık, istediğinize takabilirsiniz ;(0-1 hariç)
int buzzer_pin = 4;  // 4 nolu pine taktık, istediğinize takabilirsiniz ;(0-1 hariç)
LiquidCrystal_I2C lcd(0x3F,20,4);  // arduino ide den i2c_scanner yapıp kendi adresinizi öğreniniz
unsigned long zaman_say_previousTime = 0;
// unsigned long zaman_say_interval = 500; // 500 milisaniye (0.5 saniye)
#include <hakan_bisiklet.h>


 
void setup(){
  lcd.createChar(0, dolu_kutu); // Dolu kutu karakterini indeks 0'ya yükle
  lcd.init();                     
  lcd.clear();
  lcd.backlight();
   lcd_intro(3);
  pinMode(hall_pin, INPUT_PULLUP);
  pinMode(buzzer_pin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  say();
  //  sesli_isikli_uyari();
  //if(zaman_say(3000)  ) hiz=0.0;/// 3 saniye içinde 
            hesapla_mesafe();
            hesapla_hiz();

}
 
