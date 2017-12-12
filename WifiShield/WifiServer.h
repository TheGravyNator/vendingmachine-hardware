#ifndef WifiServer_h
#define WifiServer_h

#include "Arduino.h"
#include "JSONParser.h"
#include "ArduinoCommunicator.h"
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

class POSTReceiver;

class WifiServer
{
  public:
  WifiServer(int serverport);
  void runServer();
  String getArgument(String argument);
  private:
  ESP8266WebServer _espserver;
};

#endif
