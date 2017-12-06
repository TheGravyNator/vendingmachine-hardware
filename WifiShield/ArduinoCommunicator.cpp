#include "Arduino.h"
#include "ArduinoCommunicator.h"
#include <SoftwareSerial.h>

ArduinoCommunicator::ArduinoCommunicator(SoftwareSerial* arduinoserial)
{
  _arduinoserial = arduinoserial;
}

void ArduinoCommunicator::beginSerial(int baud)
{
  _arduinoserial->begin(baud);
}

