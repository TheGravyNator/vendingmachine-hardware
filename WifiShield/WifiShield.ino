#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SoftwareSerial.h>
#include "Secret.h"
class WifiConnection
{
  public:
  WifiConnection(char* ssid, char* password);
  char* _wifissid; //The SSID of the network
  char* _wifipassword; //The password of the network
WifiConnection::WifiConnection(char* ssid, char* password)
{
  _wifissid = ssid;
  _wifipassword = password;
}
  private:
};

void setup()
{
}

void loop()
{
}
