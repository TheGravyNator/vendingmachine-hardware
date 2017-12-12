#include "Arduino.h"
#include "WifiServer.h"
#include "JSONParser.h"
#include "ArduinoCommunicator.h"
#include <SoftwareSerial.h>

WifiServer::WifiServer(int serverport)
{
  ESP8266WebServer server(serverport);
  _espserver = server;
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


