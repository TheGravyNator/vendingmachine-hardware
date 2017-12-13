#include "Arduino.h"
#include "OrderHandler.h"
#include "Relay.h"
#include "RelayHiLo.h"
#include "SodaRequest.h"
#include "Constants.h"

void OrderHandler::init(RelayHiLo* relay1, RelayHiLo* relay2, RelayHiLo* relay3, RelayHiLo* relay4, Relay* relay5)
{
  _relay1 = relay1;
  _relay2 = relay2;
  _relay3 = relay3;
  _relay4 = relay4;
  _relay5 = relay5;
}

