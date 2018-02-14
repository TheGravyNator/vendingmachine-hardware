#include "Arduino.h"
#include "WifiServer.h"
#include "JSONParser.h"
#include "SodaRequest.h"
#include "QueueList.h"
#include "StockCheck.h"

WifiServer::WifiServer(int serverport, JSONParser jsonparser, QueueList <struct SodaRequest>* queue, StockCheck stockcheck) 
{
  ESP8266WebServer server(serverport);
  _espserver = server;
  _jsonparser = jsonparser;
  _queue = queue;
  _stockcheck = stockcheck;
}

void WifiServer::startServer()
{
  _espserver.on("/", HTTP_POST, [this]()
  {
    if(_espserver.arg("plain") == false)
    {
      _espserver.send(200, "text/plain", "Body not received");
    }
    struct SodaRequest request = _jsonparser.parseJSON(_espserver.arg("plain"));
    if(_stockcheck.isEmpty((String)request.slot) == true)
    {
      Serial.println((String)request.slot + "is empty");
      _espserver.send(200, "text/plain", "Out of stock");
    }
    else
    {
      _espserver.send(200, "text/plain", "Body received");
      SodaRequest order = {(String)request.slot, (int)request.soda_amount};
      _queue->push(order);
    }
  });
  _espserver.begin();
}

void WifiServer::runServer()
{
  _espserver.handleClient();
}


