#include <Arduino.h>  // digitalWrite(), OUTPUT
#include "Led.h"

void Led::_setByIsOn() {
  digitalWrite(this->pinNumber, this->_isOn);
}

Led::Led(uint8_t pinNumber)
  : Module(pinNumber)
{ }

void Led::setup() {
  this->Module::setup(OUTPUT)
}

void Led::set(bool isOn) {
  this->_isOn = isOn;
  this->_setByIsOn();
}

void Led::toggle() {
  this->_isOn = !this->_isOn;
  this->_setByIsOn();
}

void Led::on() {
  this->_isOn = true;
  this->_setByIsOn();
}

void Led::off() {
  this->_isOn = false;
  this->_setByIsOn();
}
