#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"


RF24 radio(7,8); // CE, CSN
char giden_komut[32];

  #define pin_far 2
  #define pin_korna 4
  #define pin_gaz_sag A0
  #define pin_gaz_sol A1
  
  signed short rightSpeed=0;
  signed short leftSpeed=0;
  uint8_t far_durum=0;
  uint8_t korna_durum=0; 

void setup() {
  
  pinMode( pin_far , INPUT_PULLUP );
  pinMode( pin_korna , INPUT_PULLUP );
  pinMode( pin_gaz_sag , INPUT );
  pinMode( pin_gaz_sol , INPUT );

  radio.begin();
  Serial.begin(9600);
  radio.openWritingPipe(0xF0F0F0F0E12E);
  radio.setPALevel(RF24_PA_MIN); // en düşük seviye enerji tüketimi , düşük sinyal menzili
  radio.stopListening();//verici  modunda çalış. 
}

void loop() {

  rightSpeed =map( analogRead( pin_gaz_sag ) , 300, 580 , 0 ,255);
  leftSpeed =map( analogRead( pin_gaz_sol ) , 300, 580 , 0 ,255);
  far_durum = !digitalRead( pin_far ); 
  korna_durum = !digitalRead( pin_korna ); 

  sprintf( giden_komut , "%d,%d,%d,%d", rightSpeed , leftSpeed , far_durum , korna_durum );


  // strcpy(giden_komut,"180,-190,0,1");
  radio.write(&giden_komut , sizeof(giden_komut));
  Serial.print("Kumanda:");
  Serial.println(giden_komut);
  delay(20);
}
