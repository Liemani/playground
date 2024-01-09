#include <Arduino.h>  // byte, INPUT_PULLUP, digitalPinToInterrupt(), attachInterrupt(), CHANGE, digitalRead()

#include "Pir.h"

Pir::Pir(byte pinNumber, void (*interruptHandler)())
{
  this->pinNumber = pinNumber;
  pinMode(this->pinNumber, INPUT_PULLUP);
  const byte interruptPinNumber = digitalPinToInterrupt(this->pinNumber);
  attachInterrupt(interruptPinNumber, interruptHandler, CHANGE);
}

int Pir::value() {
  return digitalRead(this->pinNumber);
}
