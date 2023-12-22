#include <SoftwareSerial.h>
#include "SerialCommunication.h"
#include "SerialCommunicatable.h"

SerialCommunication::SerialCommunication(const SerialCommunicatable& serialCommunicatable)
: SoftwareSerial(serialCommunicatable.rxPinNumber, serialCommunicatable.txPinNumber)
{ }
