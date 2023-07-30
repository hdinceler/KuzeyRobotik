#include <SPI.h>
#include <RF24.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

RF24 radio(9, 10); // CE, CSN pimlerini belirtin
LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int teker_sag = 0;
int teker_sol = 0;
int kol_sag = 0;
int kol_sol = 0;
int sinyal_korna = 0;
int sinyal_lamba = 0;

char buff[32];

void setup() {
  // lcd.init();                      // initialize the lcd 
  // lcd.backlight();
  // lcd.setCursor(3,0);
  // lcd.print("Hello, world!");
  
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0D2LL); // Mehmet'in gönderim adresi
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL); // Ahmet'in alım adresi
  radio.startListening(); // Alıcı modunu başlatın
}

void loop() {
  if (radio.available()) {
    radio.read(&ayar_deger, sizeof(ayar_deger));
    if(ayar_deger>50) Serial.println("50 den buyuk");
    if(ayar_deger>100) Serial.println("100 den buyuk");
    Serial.println(ayar_deger);
  }
}
