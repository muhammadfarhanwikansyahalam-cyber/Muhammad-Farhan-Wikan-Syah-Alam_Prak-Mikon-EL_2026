#include <Arduino.h>
 
#define LED_PIN 2
#define PUSHBUTTON 5


void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  pinMode(PUSHBUTTON, INPUT);
}
 
void loop() {

  

  if (digitalRead(PUSHBUTTON == LOW)){  
    digitalWrite(LED_PIN, LOW);
  } else {
      digitalWrite(LED_PIN, HIGH);
  }
}
