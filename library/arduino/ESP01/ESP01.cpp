#include "arduino.h"
#include "ESP01.h"

ESP01::ESP01(uint8_t rxPinNumber, uint8_t txPinNumber)
: SerialCommunicatable(rxPinNumber, txPinNumber)
{ }
