#ifndef WifiConnection_h
#define WifiConnection_h

#include "Arduino.h"

class WifiConnection
{
  public:
  WifiConnection(char* ssid, char* password);
  void wifiConnect();
  private:
  char* _wifissid; //The SSID of the network
  char* _wifipassword; //The password of the network
};

#endif
