#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <SoftwareSerial.h>
#include "SerialCommunicatable.h"

class SerialCommunication : public SoftwareSerial {

private :

public :
  explicit SerialCommunication(const SerialCommunicatable& serialCommunicatable);

};

#endif  // SERIALCOMMUNICATION_H
