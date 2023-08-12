#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define pin_R1 3 //~PWM
#define pin_R2 5 //~PWM
#define pin_L1 9 //~PWM
#define pin_L2 6 //~PWM


#define pin_far A5 //DIGITAL
#define pin_korna A4 //DIGITAL

//MESAFE ÖLÇÜM BİLDİRİMLERİ
#define pin_mesafe_trig 2 //mesafe ölçümü sinyal gönderme (trigger) pini
#define pin_mesafe_echo 4 //mesafe ölçümü sinyal alma (echo) piniunsigned long sonPulseZamani = 0;
unsigned long baslangicZamani = 0;
unsigned long sonPulseZamani = 0; // Global scope'da tanımlanan değişken
const unsigned long maxMesafeZaman = 30000; // Maksimum mesafe ölçüm zamanı (us)
int mesafe_cm = 0;


#include "araba_kutuphane.h"

RF24 radio(7,8); // CE, CSN pimleri

signed short rightSpeed=0;
signed short leftSpeed=0;
uint8_t far_durum=0;
uint8_t korna_durum=0;
char buff[10];
char gelen_komut[32] = "";

const unsigned long okumaAraligi = 1000; // Mesafe okuma aralığı (ms)

void setup() {
  
  pinMode(pin_mesafe_trig, OUTPUT);
  pinMode(pin_mesafe_echo, INPUT);

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
  all_stop();
}

void loop() {


// //MESAFE ÖLÇÜM
// unsigned long simdikiZaman = millis();
//  if (simdikiZaman - sonOkumaZamani >= okumaAraligi) {
//     int mesafe = mesafe_olc();
    
//     Serial.print("Mesafe: ");
//     Serial.print(mesafe);
//     Serial.println(" cm");
    
//     sonOkumaZamani = simdikiZaman;
//   }

//RADYO İLETİŞİM
  if (radio.available()) {
    
    radio.read(&gelen_komut, sizeof(gelen_komut));
    Serial.print("araba:");
    // Serial.println(gelen_komut);
    
    strcpy( buff , strtok( gelen_komut,  "," ) );
    leftSpeed= atoi(buff);
    

    strcpy( buff , strtok(NULL,  "," ) );
    rightSpeed= atoi(buff);


    strcpy( buff , strtok(NULL,  "," ) );
    far_durum= atoi(buff);
    
    strcpy( buff , strtok(NULL,  "," ) );
    korna_durum= atoi(buff);
    

    // Serial.print("left:");
    // Serial.println(rightSpeed);
    // Serial.print(" , right:");
    // Serial.print(rightSpeed);
    // Serial.print("  , far:");
    Serial.println(korna_durum);
    Serial.println(far_durum);;                                                                                                                                                                                  
    // Serial.print(" , korna:");
    // Serial.print(korna_durum);
    // Serial.println();

    run_left(leftSpeed);
    run_right(rightSpeed);
    digitalWrite(pin_far,far_durum);
    digitalWrite(pin_korna, korna_durum);

  } else   all_stop();
}
