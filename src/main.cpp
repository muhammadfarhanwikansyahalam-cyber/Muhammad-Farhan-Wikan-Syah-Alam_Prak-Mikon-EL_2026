const int potPin = 2;
const int ledMerah = 25;
const int ledKuning = 26;
const int ledHijau = 27;
const int tombol = 4;

void setup() {
  Serial.begin(115200);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(tombol, INPUT_PULLUP);
}

void loop() {
  int adcValue = analogRead(potPin);

  if (digitalRead(tombol) == LOW) {
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, LOW);
  }
  else {
    if (adcValue < 1300) {
      digitalWrite(ledMerah, HIGH);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, LOW);
    }
    else if (adcValue < 2600) {
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledHijau, LOW);
    }
    else {
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledHijau, HIGH);
    }
  }

  Serial.print("ADC: ");
  Serial.println(adcValue);

  delay(100);
}