#include "DHT.h"

#define SERIAL_BAUD_RATE 9600
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    return;
  }

  Serial.print(F("{\"temperature\":"));
  Serial.print(t);
  Serial.print(F(",\"humidity\":"));
  Serial.print(h);
  Serial.print(F("}"));
  Serial.println();
}
