#include "Arduino.h"
#include "MDNSHandler.h"
#include <ESP8266mDNS.h>

void MDNSHandler::startResponder(char* hostname)
{
  if (_mdnsresponder.begin(hostname, WiFi.localIP()))
  {
    Serial.println("MDNS responder started");
    Serial.println("Connect to http://VendingMachineAPI.local.");
  }
}
