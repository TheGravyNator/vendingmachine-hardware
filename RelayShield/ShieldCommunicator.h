#ifndef ShieldCommunicator_h
#define ShieldCommunicator_h

#include "Arduino.h"
#include "SodaRequest.h"
#include <SoftwareSerial.h>

class ShieldCommunicator
{
  public:
  ShieldCommunicator();
  void beginSerial(SoftwareSerial* serial, int baud);
  private:
  SoftwareSerial* _shieldcomm;
};

#endif
