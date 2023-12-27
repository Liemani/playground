#ifndef PIR_H
#define PIR_H

#include "Module.h"

//  Pir is designed to use interrupt
//  pinNumber : must interruptable pin
class Pir : public Module {

private :

public :
  Pir(uint8_t pinNumber, void (*interruptHandler)());

  void setup();

  int value();

};  // Pir

#endif  // PIR_H
