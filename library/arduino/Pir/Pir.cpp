#include <Arduino.h>  // digitalRead, INPUT_PULLUP
#include "Pir.h"

Pir::Pir(uint8_t pinNumber, void (*interruptHandler)())
  : Module(pinNumber, INPUT_PULLUP)
{
}

Pir::setup() {
  const uint8_t interruptPinNumber = digitalPinToInterrupt(this->pinNumber);
  attachInterrupt(interruptPinNumber, interruptHandler, CHANGE);
}

int Pir::value() {
  return digitalRead(this->pinNumber);
}
