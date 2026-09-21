#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
Adafruit_MPU6050 mpu;
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Wire.begin( 21, 22);
Serial.begin(115200);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  mpu.begin();
}




void loop() {

display.clearDisplay();
display.setCursor(0,10);

sensors_event_t a, g, temp;
mpu.getEvent(&a, &g, &temp);

  display.print (a.acceleration.x);
  display.setCursor(0,20);
display.print (a.acceleration.y);
display.setCursor(0,30);
display.print (a.acceleration.z);
display.display();
delay(1000);
}