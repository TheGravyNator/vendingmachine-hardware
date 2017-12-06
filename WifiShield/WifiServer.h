#ifndef WifiServer_h
#define WifiServer_h

#include "Arduino.h"
#include "POSTReceiver.h"
#include <ESP8266WebServer.h>

class POSTReceiver;

class WifiServer
{
  public:
  WifiServer(int serverport);
  void startServer(POSTReceiver receiver);
  void runServer();
  String getArgument(String argument);
  private:
  ESP8266WebServer _espserver;
};

#endif
