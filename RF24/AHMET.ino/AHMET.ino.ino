#include <SPI.h>
#include <RF24.h>

int teker_sag = 0;
int teker_sol = 0;
int kol_sag = 0;
int kol_sol = 0;
int sinyal_korna = 0;
int sinyal_lamba = 0;
//int sinyal_korna = 0;
RF24 radio(9, 10); // CE, CSN pimlerini belirtin
char buff[32];

unsigned long previousMillis = 0;
const unsigned long interval = 10; // 50 ms'lik zaman dilimi

void setup() {
  analogReference(EXTERNAL);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0E1LL); // Bu dosyanın gönderim adresi
  radio.openReadingPipe(1, 0xF0F0F0F0D2LL); // Karşı tarafın alım adresi
  radio.stopListening(); // Gönderici modunda çalış
}

void loop() {
   unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    teker_sag = map(analogRead(A0), 0, 1023, -255, 255);
    teker_sol = map(analogRead(A1), 0, 1023, -255, 255);
    kol_sag = map(analogRead(A2), 0, 1023, 0, 180);
    kol_sol = map(analogRead(A3), 0, 1023, 0, 180);
    sinyal_korna = map(analogRead(A4), 0, 1023, 0, 255);
    sinyal_lamba = map(analogRead(A5), 0, 1023, 0, 255);

    sprintf(buff,
      "move,%d,%d,%d,%d,%d,%d",
      teker_sag,teker_sol,kol_sag,kol_sol,sinyal_korna,sinyal_lamba);
    Serial.println( buff );
    radio.write(&buff, sizeof(buff));
  }
}

