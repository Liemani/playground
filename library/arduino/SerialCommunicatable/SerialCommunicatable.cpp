#include "arduino.h"
#include "SerialCommunicatable.h"

SerialCommunicatable::SerialCommunicatable(uint8_t rxPinNumber, uint8_t txPinNumber)
: rxPinNumber(rxPinNumber), txPinNumber(txPinNumber)
{ }
