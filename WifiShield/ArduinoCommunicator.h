#ifndef ArduinoCommunicator_h
#define ArduinoCommunicator_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class ArduinoCommunicator
{
  public:
  ArduinoCommunicator(SoftwareSerial* arduinoserial);
  void beginSerial(int baud);
  private:
  SoftwareSerial* _arduinoserial;
};

#endif
