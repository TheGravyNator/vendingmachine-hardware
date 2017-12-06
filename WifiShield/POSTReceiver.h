#ifndef POSTReceiver_h
#define POSTReceiver_h

#include "Arduino.h"
#include "WifiServer.h"
#include <ESP8266WebServer.h>

class WifiServer;

class POSTReceiver
{
  public:
  POSTReceiver(WifiServer server);
  void receivePost(ESP8266WebServer server);
};

#endif
