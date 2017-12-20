#include "Arduino.h"
#include "WifiServer.h"
#include "JSONParser.h"
#include "SodaRequest.h"
#include "QueueList.h"
#include <SoftwareSerial.h>

WifiServer::WifiServer(int serverport, JSONParser jsonparser, QueueList <struct SodaRequest>* queue) 
{
  ESP8266WebServer server(serverport);
  _espserver = server;
  _jsonparser = jsonparser;
  _queue = queue;
}

void WifiServer::startServer()
{
  _espserver.on("/", HTTP_POST, [this]()
  {
    if (_espserver.arg("plain") == false)
    {
      _espserver.send(200, "text/plain", "Body not received");
    }
    struct SodaRequest request = _jsonparser.parseJSON(_espserver.arg("plain"));
    _espserver.send(200, "text/plain", "Body received!");
    _arduinocomm.sendOrder((String)request.soda_type + ":" + (String)request.soda_amount);
  });
  _espserver.begin();
}

void WifiServer::runServer()
{
  _espserver.handleClient();
}


