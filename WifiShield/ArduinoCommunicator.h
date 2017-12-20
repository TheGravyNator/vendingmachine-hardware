#ifndef ArduinoCommunicator_h
#define ArduinoCommunicator_h

#include "Arduino.h"
#include "SodaRequest.h"
#include "DispensingIndicator.h"
#include <SoftwareSerial.h>

class ArduinoCommunicator
{
  public:
  ArduinoCommunicator();
  void beginSerial(SoftwareSerial* serial, int baud);
  void setDispensingIndicator(DispensingIndicator* dispensing);
  void sendOrder(SodaRequest order);
  private:
  SoftwareSerial* _arduinocomm;
  DispensingIndicator* _dispensing;
};

#endif
