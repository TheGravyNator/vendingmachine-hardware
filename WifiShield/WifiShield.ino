#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SoftwareSerial.h>
#include "Secret.h"
class WifiServer
{
  public:
  WifiServer(int serverport);
  void startServer();
  void Update();
  private:
  ESP8266WebServer _espserver;
};

WifiServer::WifiServer(int serverport)
{
  ESP8266WebServer server(serverport);
  _espserver = server;
}

void WifiServer::startServer()
{
  _espserver.on("/", [&]()
  {
    _espserver.send(200, "text/plain", "Welcome to the 23G Soda API!");
  });
  _espserver.begin();
}

void WifiServer::Update()
{
  _espserver.handleClient();
}


class WifiConnection
{
  public:
  WifiConnection(char* ssid, char* password);
  void wifiConnect();
  private:
  char* _wifissid; //The SSID of the network
  char* _wifipassword; //The password of the network
};

WifiConnection::WifiConnection(char* ssid, char* password)
{
  _wifissid = ssid;
  _wifipassword = password;
}
void WifiConnection::wifiConnect()
{
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(_wifissid, _wifipassword);
  delay(1000);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(_wifissid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

class MDNSHandler
{
  public:
  void startResponder(char* hostname);
  private:
  MDNSResponder _mdnsresponder;
};

void MDNSHandler::startResponder(char* hostname)
{
  if (_mdnsresponder.begin(hostname, WiFi.localIP()))
  {
    Serial.println("MDNS responder started");
    Serial.print("Connect to http://VendingMachineAPI.local.");
  }
}

class ArduinoCommunicator
{
  public:
  ArduinoCommunicator(int RX, int TX);
  private:
};
void setup()
{
}

void loop()
{
}
