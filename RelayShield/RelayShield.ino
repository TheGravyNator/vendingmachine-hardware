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

ShieldCommunicator shieldcomm;
RelayHiLo relay1(RELAY1_HI, RELAY1_LO);
RelayHiLo relay2(RELAY2_HI, RELAY2_LO);
RelayHiLo relay3(RELAY3_HI, RELAY3_LO);
RelayHiLo relay4(RELAY4_HI, RELAY4_LO);
Relay relay5(RELAY5);
OrderHandler orderhandler;

struct SodaRequest order;

void setup() 
{
  

  Serial.begin(115200);
  shieldcomm.beginSerial(new SoftwareSerial(RX_SERIAL, TX_SERIAL), 9600);
  relay1.init();
  relay2.init();
  relay3.init();
  relay4.init();
  relay5.init();
}

void loop() 
{
  

}
