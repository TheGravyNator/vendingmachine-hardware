#ifndef ArduinoCommunicator_h
#define ArduinoCommunicator_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class ArduinoCommunicator
{
  public:
  ArduinoCommunicator();
  void beginSerial(SoftwareSerial* serial);
  private:
  SoftwareSerial* _arduinocomm;
};

#endif
