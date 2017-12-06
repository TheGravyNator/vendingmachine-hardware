#include "Arduino.h"
#include "WifiServer.h"
#include "POSTReceiver.h"

WifiServer::WifiServer(int serverport)
{
  ESP8266WebServer server(serverport);
  _espserver = server;
}

void WifiServer::startServer(POSTReceiver receiver)
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


