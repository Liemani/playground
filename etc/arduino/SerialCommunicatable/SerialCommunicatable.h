#ifndef SERIALCOMMUNICATABLE_H
#define SERIALCOMMUNICATABLE_H

class SerialCommunicatable {

private :

public :
  const uint8_t rxPinNumber;
  const uint8_t txPinNumber;

  SerialCommunicatable(uint8_t _rxPinNumber, uint8_t _txPinNumber);

};

#endif  // SERIALCOMMUNICATABLE_H
