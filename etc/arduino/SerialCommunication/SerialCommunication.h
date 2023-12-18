#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <memory>
#include <SoftwareSerial.h>
#include "SerialCommunicatable.h"

class SerialCommunication : SoftwareSerial {

private :

public :
  const std::shared_ptr<SerialCommunicatable> serialCommunicatable;

  explicit SerialCommunication(std::shared_ptr<SerialCommunicatable> serialCommunicatable);

};

#endif  // SERIALCOMMUNICATION_H
