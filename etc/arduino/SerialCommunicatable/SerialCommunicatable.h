#ifndef SERIALCOMMUNICATABLE_H
#define SERIALCOMMUNICATABLE_H

#include "arduino.h"

class SerialCommunicatable {

private :

public :
  const uint8_t rxPinNumber;
  const uint8_t txPinNumber;

  SerialCommunicatable(uint8_t rxPinNumber, uint8_t txPinNumber);

};

#endif  // SERIALCOMMUNICATABLE_H
