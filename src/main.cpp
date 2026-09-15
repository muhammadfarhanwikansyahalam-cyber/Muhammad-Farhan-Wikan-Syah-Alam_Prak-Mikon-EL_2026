#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SCL_PIN 26
#define SDA_PIN 14

Adafruit_BME280 bme;

const int pwmPin = 32;

const int freq = 5000;
const int pwmChannel = 0;
const int resolution = 8;

void setup() {
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(pwmPin, pwmChannel);

  Wire.begin(SDA_PIN, SCL_PIN);

  bme.begin(0x76);
}

void loop() {
  float suhu = bme.readTemperature();

  ledcWrite(pwmChannel, suhu * 10);

  delay(15);
}