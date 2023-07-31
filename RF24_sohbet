#include <SPI.h>
#include <RF24.h>
#include<string.h>
  RF24 radio(9, 10); // CE, CSN pimlerini belirtin
  char gelen_mesaj[64];
  char giden_mesaj[64]; 
void setup() {
  radio.begin();
 
  //hakan bu kanaldan konuşacak 0xF0F0F0F0E1LL
  radio.openWritingPipe(0xE0F0F0F0E1LL); //  gönderim adresi
  
  
  //yağız bu kanaldan konuşacak 0xF0F0F0F0E2LL  (hakan bu kanaldan yağız'ı dinleyecek)
  radio.openReadingPipe(1, 0xE0F0F0F0E2LL); //   alım adresi
  radio.startListening(); // Alıcı modunu başlatın
  Serial.begin(9600);

}

void loop() {
  
 if( radio.available() ){
   radio.read( &gelen_mesaj , sizeof(gelen_mesaj) );
   Serial.println( gelen_mesaj );
 }

Serial.readBytes(giden_mesaj , sizeof(giden_mesaj));
  if( strlen(giden_mesaj)>0  ){
    radio.stopListening();
    radio.write(&giden_mesaj , sizeof(giden_mesaj));
    radio.startListening();
  }
  // radio.write(&konsol , sizeof(konsol));
  //delay(1000);
 

}
