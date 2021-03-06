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

void OrderHandler::executeOrder(struct SodaRequest request)
{
  if(request.slot == "slot_1")
  {
    for(int i = 0; i < request.soda_amount; i++)
    {
      _relay1->trigger(DELAY_AMOUNT_UP, DELAY_AMOUNT_DOWN);
    }
  }
  else if(request.slot == "slot_2")
  {
    for(int i = 0; i < request.soda_amount; i++)
    {
      _relay2->trigger(DELAY_AMOUNT_UP, DELAY_AMOUNT_DOWN);
    }
  }
  else if(request.slot == "slot_3")
  {
    for(int i = 0; i < request.soda_amount; i++)
    {
      _relay3->trigger(DELAY_AMOUNT_UP, DELAY_AMOUNT_DOWN);
    }
  }
  else if(request.slot == "slot_4")
  {
    for(int i = 0; i < request.soda_amount; i++)
    {
      _relay4->trigger(DELAY_AMOUNT_UP, DELAY_AMOUNT_DOWN);
    }
  }
  else if(request.slot == "slot_5")
  {
    for(int i = 0; i < request.soda_amount; i++)
    {
      _relay5->trigger(DELAY_AMOUNT_UP, DELAY_AMOUNT_DOWN);
    }
  }
}

