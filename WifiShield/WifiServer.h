#ifndef WifiServer_h
#define WifiServer_h

#include "Arduino.h"
#include "JSONParser.h"
#include "SodaRequest.h"
#include "StockCheck.h"
#include "QueueList.h"
#include <ESP8266WebServer.h>

class WifiServer
{
  public:
  WifiServer(int serverport, JSONParser jsonparser, QueueList <struct SodaRequest>* queue, StockCheck stockcheck);
  void startServer();
  void runServer();
  private:
  ESP8266WebServer _espserver;
  JSONParser _jsonparser;
  QueueList <struct SodaRequest>* _queue;
  StockCheck _stockcheck;
};

#endif
