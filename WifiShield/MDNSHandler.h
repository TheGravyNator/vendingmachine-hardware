#ifndef MDNSHandler_h
#define MDNSHandler_h

#include "Arduino.h"
#include <ESP8266mDNS.h>

class MDNSHandler
{
  public:
  void startResponder(char* hostname);
  private:
  MDNSResponder _mdnsresponder;
};

#endif
