# include "PmodAD1.hpp"

#include "Arduino.h"
#include <SPI.h>

PmodAD1::PmodAD1(uint8_t csPinNumber)
: _csPinNumber(csPinNumber)
{
}

void PmodAD1::begin() {
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV2);

  pinMode(_csPinNumber, OUTPUT);
  digitalWrite(_csPinNumber, HIGH);

  _word.nl = '\n';
}

byte* PmodAD1::read() {
  digitalWrite(_csPinNumber, LOW);
  _word.highByte = SPI.transfer(0);
  _word.lowByte = SPI.transfer(0);
  digitalWrite(_csPinNumber, HIGH);
  return (byte*)&_word;
}
