#ifndef ShieldCommunicator_h
#define ShieldCommunicator_h

#include "Arduino.h"
#include "SodaRequest.h"
#include <SoftwareSerial.h>

class ShieldCommunicator
{
  public:
  ShieldCommunicator();
  private:
  SoftwareSerial* _shieldcomm;
};

#endif
