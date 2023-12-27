#ifndef LED_H
#define LED_H

#include "Module.h"

class Led : public Module {

private :
  bool _isOn = false;

  void _setByIsOn();

public :
  Led(uint8_t pinNumber);

  void setup();
  void set(bool isOn);
  void toggle();
  void on();
  void off();

};  // Led

#endif  // LED_H
