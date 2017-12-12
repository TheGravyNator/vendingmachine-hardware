#ifndef ArduinoCommunicator_h
#define ArduinoCommunicator_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class ArduinoCommunicator
{
  public:
  ArduinoCommunicator();
  void beginSerial(SoftwareSerial* serial, int baud);
  void sendOrder(String message);
  private:
  SoftwareSerial* _arduinocomm;
};

#endif
