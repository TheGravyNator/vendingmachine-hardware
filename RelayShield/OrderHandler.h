#ifndef OrderHandler_h
#define OrderHandler_h

#include "Arduino.h"
#include "Relay.h"
#include "RelayHiLo.h"
#include "SodaRequest.h"

class OrderHandler
{
  public:
  private:
  RelayHiLo* _relay1;
  RelayHiLo* _relay2;
  RelayHiLo* _relay3;
  RelayHiLo* _relay4;
  Relay* _relay5;
};

#endif
