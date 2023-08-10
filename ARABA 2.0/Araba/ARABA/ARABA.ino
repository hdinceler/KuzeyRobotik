#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define pin_R1 3 //~PWM
#define pin_R2 5 //~PWM
#define pin_L1 6 //~PWM
#define pin_L2 9 //~PWM

#include "araba_kutuphane.h"

RF24 radio(7,8); // CE, CSN pimleri
#define pin_far 2 //DIGITAL
#define pin_korna 4 //DIGITAL

signed short rightSpeed=0;
signed short leftSpeed=0;
uint8_t far_durum=0;
uint8_t korna_durum=0;
char buff[10];
char gelen_komut[32] = "";
void setup() {
  pinMode( pin_far, OUTPUT);
  pinMode( pin_korna , OUTPUT);
  pinMode( pin_R1 , OUTPUT);
  pinMode( pin_R2 , OUTPUT);
  pinMode( pin_L1 , OUTPUT);
  pinMode( pin_L2 , OUTPUT);

  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, 0xF0F0F0F0E12E); // Vericinin yazma hattı adresi
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    
    radio.read(&gelen_komut, sizeof(gelen_komut));
    // Serial.print("araba:");
    // Serial.println(gelen_komut);
    
    strcpy( buff , strtok( gelen_komut,  "," ) );
    rightSpeed= atoi(buff);
    

    strcpy( buff , strtok(NULL,  "," ) );
    leftSpeed= atoi(buff);


    strcpy( buff , strtok(NULL,  "," ) );
    far_durum= atoi(buff);
    
    strcpy( buff , strtok(NULL,  "," ) );
    korna_durum= atoi(buff);
    

    // Serial.print("left:");
    // Serial.print(leftSpeed);
    // Serial.print(" , right:");
    // Serial.print(rightSpeed);
    // Serial.print("  , far:");
    // Serial.print(far_durum);                                                                                                                                                                                  
    // Serial.print(" , korna:");
    // Serial.print(korna_durum);
    Serial.println();

    run_left(leftSpeed);
    run_right(rightSpeed);
    digitalWrite(pin_far,far_durum);
    digitalWrite(pin_korna, korna_durum);


  }
}
