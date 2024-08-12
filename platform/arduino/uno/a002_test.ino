#ifdef a005
// print text value
#include "PmodAD1.hpp"

#define vccPinNumber 7
#define csPinNumber 10

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

  pinMode(vccPinNumber, OUTPUT);
  digitalWrite(vccPinNumber, HIGH);

  deadline = micros() + cyclePeriod;
}

void loop() {
  Serial.print(*(unsigned short*)ad1.read());
  Serial.print('\n');
  delayMicroseconds(moveDeadline());
}
#endif

#ifdef a004
// test performance
#include "PmodAD1.hpp"

#define vccPinNumber 7
#define csPinNumber 10

#define serialBaudRate 2000000
#define cyclePerSecond 20000

#define testCount 1000

#define cyclePeriod (1000000 / cyclePerSecond)

PmodAD1 ad1 = PmodAD1(csPinNumber);
unsigned long startTime;
unsigned long deadline;

int count;

unsigned long moveDeadline() {
  unsigned long sleeptime = deadline - micros();
  deadline += cyclePeriod;
  return max(sleeptime, 0);
}

void setup() {
  Serial.begin(serialBaudRate);
  ad1.begin();

  pinMode(vccPinNumber, OUTPUT);
  digitalWrite(vccPinNumber, HIGH);

  deadline = micros() + cyclePeriod;

  count = 0;
}

void loop() {
  if (count >= testCount) {
    if (count == testCount) {
      Serial.println(micros() - startTime);
      ++count;
    }
    return;
  }

  Serial.write(ad1.read(), 3);
  delayMicroseconds(moveDeadline());

  ++count;
}
#endif

#ifdef a003
// test PmodAD1
#include "PmodAD1.hpp"

#define serialBaudRate 2000000

#define csPinNumber 10
#define vcc 7

PmodAD1 ad1 = PmodAD1(csPinNumber);

void setup() {
  Serial.begin(serialBaudRate);
  ad1.begin();

  pinMode(vcc, OUTPUT);
  digitalWrite(vcc, HIGH);
}

void loop() {
  Serial.println(*(short*)ad1.read());
}
#endif
