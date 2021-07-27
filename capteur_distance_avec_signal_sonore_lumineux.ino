#include "SR04.h"
#include "pitches.h"

#define TRIG_PIN 3
#define ECHO_PIN 2
#define BUZZER_PIN 10
#define RED 7
#define GREEN 6
#define BLUE 5

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   Serial.begin(9600);
   pinMode(RED, OUTPUT);
   pinMode(GREEN, OUTPUT);
   pinMode(BLUE, OUTPUT);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");

   if(a < 50){
    tone(BUZZER_PIN, NOTE_C5, 50);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    delay(100);
   }

   if(a > 50 && a < 100){
    tone(BUZZER_PIN, NOTE_C5, 100);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
    delay(1000);
   }

   if(a > 100){
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
    delay(2000);
   }

   delay(100);
}
