#include <arduino.h>

const int pwmPin = 16;
const int freq = 5000;

const int resolution = 8;

void setup() {
  ledcSetup(0, freq, resolution);
  
  ledcSetup(1, freq, resolution);
  
  ledcSetup(2, freq, resolution);
 
    ledcAttachPin(17, 0);
  ledcAttachPin(18, 1);
   ledcAttachPin(19, 2);
  

}

void loop() {
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(0, dutyCycle);
    delay(15);
  }
 for(int dutyCycle = 255; dutyCycle >=0; dutyCycle--) {
    ledcWrite(0, dutyCycle);
    delay(15);
  }

   for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(1, dutyCycle);
    delay(15);
  }
 for(int dutyCycle = 255; dutyCycle >=0; dutyCycle--) {
    ledcWrite(1, dutyCycle);
    delay(15);
  }
   for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(2, dutyCycle);
    delay(15);
  }
 for(int dutyCycle = 255; dutyCycle >=0; dutyCycle--) {
    ledcWrite(2, dutyCycle);
    delay(15);
  }
}