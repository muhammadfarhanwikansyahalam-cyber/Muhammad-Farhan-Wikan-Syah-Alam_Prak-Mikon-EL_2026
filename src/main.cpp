#define potPin 2

void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcValue = analogRead(potPin);
  float voltage = (adcValue / 4095.0) * 3.3;
  float resistance = (voltage / 3.3) * 10000.0;

  Serial.print("ADC       : ");
  Serial.println(adcValue);

  Serial.print("Tegangan  : ");
  Serial.print(voltage, 2);
  Serial.println(" V");

  Serial.print("Resistansi: ");
  Serial.print(resistance, 2);
  Serial.println(" Ohm");

  delay(500);
}