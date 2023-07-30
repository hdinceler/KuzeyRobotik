#include <Arduino.h>
#include "hakan_araba.h"
 
#include <SPI.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN pimlerini belirtin


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);


void setup() {
 lcd.begin(16,2); // LCD ekranı başlat
  lcd.backlight(); // LCD ekran arka ışığını aç
  lcd.println("Hello, World!"); // LCD ekranına yazı yazdır

  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0D2LL); //  gönderim adresi
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL); //   alım adresi
  radio.startListening(); // Alıcı modunu başlatın
  Serial.begin(9600);
  
}

void loop() {
if (radio.available()) {
    radio.read(&gelen_komut, sizeof(gelen_komut));
    kumanda_oku(gelen_komut);
    Serial.println( araba.sinyal_korna);
    lcd.println(araba.sinyal_korna);
  }else{
    //Serial.println("sinyal YOK");
  }
}
