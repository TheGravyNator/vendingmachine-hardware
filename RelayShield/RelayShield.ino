/**
 *  Name: RelayShield.ino
 *  Purpose: The main code for the Relay shield of the 23G vending machine project.
 *  It receives input from the WifiShield and controls the vending machine. 
 *
 *  @author: Christian Slabbekoorn
 *  @date: December 13th, 2017
 **/

#include <SoftwareSerial.h>

#include "ShieldCommunicator.h"
#include "Relay.h"
#include "RelayHiLo.h"
#include "Constants.h"
#include "SodaRequest.h"
#include "OrderHandler.h"
#include "DispensingIndicator.h"

ShieldCommunicator shieldcomm;
RelayHiLo relay1(RELAY1_HI, RELAY1_LO);
RelayHiLo relay2(RELAY2_HI, RELAY2_LO);
RelayHiLo relay3(RELAY3_HI, RELAY3_LO);
RelayHiLo relay4(RELAY4_HI, RELAY4_LO);
Relay relay5(RELAY5);
OrderHandler orderhandler;
DispensingIndicator dispensing(DISPENSING_INDICATOR, false);

struct SodaRequest order;

void setup() 
{
  Serial.begin(BAUD_RATE);
  shieldcomm.beginSerial(new SoftwareSerial(RX_SERIAL, TX_SERIAL), BAUD_RATE);
  relay1.init();
  relay2.init();
  relay3.init();
  relay4.init();
  relay5.init();
  orderhandler.init(&relay1, &relay2, &relay3, &relay4, &relay5);
  dispensing.init();
}

void loop() 
{
  if(shieldcomm.incoming())
  {
    order = shieldcomm.receiveOrder();
    if(order.soda_type != "" && order.soda_amount != 0)
    {
      dispensing.setIndicator(true);
      orderhandler.executeOrder(order); 
      dispensing.setIndicator(false);
    }
  }
}



