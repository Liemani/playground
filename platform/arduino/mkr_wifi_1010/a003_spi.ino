#include "PmodAD1.hpp"

#define csPinNumber 7

#define serialBaudRate 2000000
#define cyclePerSecond 20000

#define cyclePeriod (1000000 / cyclePerSecond)

PmodAD1 ad1 = PmodAD1(csPinNumber);
unsigned long deadline;

unsigned long moveDeadline() {
  unsigned long sleeptime = deadline - micros();
  deadline += cyclePeriod;
  return max(sleeptime, 0);
}

void setup() {
  Serial.begin(serialBaudRate);
  ad1.begin();

  deadline = micros() + cyclePeriod;
}

void loop() {
  Serial.write(ad1.read(), 3);
  delayMicroseconds(moveDeadline());
}