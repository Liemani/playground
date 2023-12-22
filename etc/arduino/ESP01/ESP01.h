#ifndef ESP01_H
#define ESP01_H

#include "arduino.h"
#include "SerialCommunicatable.h"

class ESP01 : public SerialCommunicatable {

private :

public :
  ESP01(uint8_t rxPinNumber, uint8_t txPinNumber);

};

#endif  // ESP01_H
