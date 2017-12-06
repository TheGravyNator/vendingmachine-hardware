#include "Arduino.h"
#include "POSTReceiver.h"
#include "WifiServer.h"
#include <ESP8266WebServer.h>

void POSTReceiver::receivePost(ESP8266WebServer server)
{
  if (server.hasArg("plain"))
  {
    server.send(400, "text/plain", "Body not received!");
  }  
  else
  {
    Serial.println("Body:" + server.hasArg("plain"));
    server.send(200, "text/plain", "Body received!");
  }
}
