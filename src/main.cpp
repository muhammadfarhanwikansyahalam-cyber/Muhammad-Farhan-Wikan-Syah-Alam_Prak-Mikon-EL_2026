#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_INA219 ina219;
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
Serial.begin(115200);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
ina219.begin();
 display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}




void loop() {
float arus = ina219.getCurrent_mA();
float tegangan_V = ina219.getBusVoltage_V();
float daya_mW = ina219.getPower_mW();

display.clearDisplay();
display.setCursor(0,10);
  display.print (arus);
  display.setCursor(0,20);
display.print (tegangan_V);
display.setCursor(0,30);
display.print (daya_mW);
display.display();
delay(1000);
}