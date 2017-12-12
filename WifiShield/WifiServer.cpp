#include "Arduino.h"
#include "WifiServer.h"
#include "JSONParser.h"
#include "ArduinoCommunicator.h"
#include <SoftwareSerial.h>

WifiServer::WifiServer(int serverport, JSONParser jsonparser) 
{
  ESP8266WebServer server(serverport);
  _espserver = server;
  _jsonparser = jsonparser;
}

{
  _espserver.on("/", [&]()
  {
    receiver.receivePost(_espserver);
  });
  _espserver.begin();
}

void WifiServer::runServer()
{
  _espserver.handleClient();
}


