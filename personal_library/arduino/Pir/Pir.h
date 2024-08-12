#ifndef PIR_H
#define PIR_H

#include <Arduion.h>  // byte

#include "Module.h"

//  Pir is designed to use interrupt
//  pinNumber : must interruptable pin
//  interruptable pin : 2, 3
//  arduino pin reference : https://roboticsbackend.com/arduino-uno-pins-a-complete-practical-guide/
class Pir : public Module {

private :

public :
  byte pinNumber;

  Pir(byte pinNumber, void (*interruptHandler)());
  Pir();

  void setup();

  int value();

};  // Pir

#endif  // PIR_H
