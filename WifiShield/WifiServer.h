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
  WifiServer(int serverport, JSONParser jsonparser);
  void startServer();
  void setArduinoCommunicator(ArduinoCommunicator arduinocomm);
  void runServer();
  String getArgument(String argument);
  private:
  ESP8266WebServer _espserver;
  JSONParser _jsonparser;
  ArduinoCommunicator _arduinocomm;
};

#endif
