#include <memory.h>
#include <SoftwareSerial.h>
#include "SerialCommunication.h"
#include "SerialCommunicatable.h"

SerialCommunication::SerialCommunication(std::shared_ptr<SerialCommunicatable> serialCommunicatable)
: SoftwareSerial(serialCommunicatable.txPinNumber, serialCommunicatable.rxPinNumber), serialCommunicatable(std::move(serialCommunicatable))
{
  
}
