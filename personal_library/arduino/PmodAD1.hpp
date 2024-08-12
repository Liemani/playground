#ifndef PMODAD1_HPP
#define PMODAD1_HPP

#include "Arduino.h"

class PmodAD1 {

public :
  PmodAD1(uint8_t csPinNumber);
  void begin();
  byte* read();

private :
  uint8_t _csPinNumber;
  struct {
    byte highByte;
    byte lowByte;
    byte nl;
  } _word;

};

#endif  // PMODAD1_HPP
