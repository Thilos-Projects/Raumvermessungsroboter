#include <Wire.h>

const int triggerPin = 2; 
const int echoPin = 15;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(triggerPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, HIGH);
  
  Serial.println("Setup Done");
}

void loop() {

  float distance = get_distance();
  // put your main code here, to run repeatedly:
  Serial.print("[Ultraschall]:: distance: ");
  Serial.println(distance);
 
  delay(100);
}


/*
Methode bietet die Distanz in verwendung von pulseIn
Signal wird ausgesendet und die Zeit gemessen, die notwneidg ist, bis Signal zurück kommt
*/
float get_distance() {

  float duration=0;
  float distance=0;

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  noInterrupts();
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Erfassung - Dauer in Mikrosekunden
  interrupts();

  distance = (duration / 2) / 29.1; // Distanz in CM
  return(distance);
}