#include "Arduino.h"
#include "ArduinoCommunicator.h"
#include <SoftwareSerial.h>

ArduinoCommunicator::ArduinoCommunicator()
{
  _arduinocomm = NULL;
}

void ArduinoCommunicator::beginSerial(SoftwareSerial* serial)
{
  _arduinoserial->begin(baud);
  _arduinocomm = serial;
}
}

