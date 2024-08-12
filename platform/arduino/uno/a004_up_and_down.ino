#define digitalPinNumber 2

void setup() {
  pinMode(digitalPinNumber, OUTPUT);
  digitalWrite(digitalPinNumber, LOW);
}

void loop() {
  digitalWrite(digitalPinNumber, HIGH);
  delayMicroseconds(1);
  digitalWrite(digitalPinNumber, LOW);
  delayMicroseconds(1);
}
