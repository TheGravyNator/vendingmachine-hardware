/**
 *  Name: WifiShield.ino
 *  Purpose: The main code for the Wifi shield of the 23G vending machine project. 
 *  It establishes connection with the API and communicates with the arduino to control the vending machine.
 * 
 *  @author: Christian Slabbekoorn
 *  @date: December 5th, 2017
 **/

//External libraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SoftwareSerial.h>

//Internal header files
#include "Secret.h"

class WifiServer
{
  public:
  WifiServer(int serverport);
  void startServer();
  void runServer();
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
    if (_espserver.hasArg("plain") == false)
    {
      _espserver.send(200, "text/plain", "Body not received");
    }
    String message = "Body received:\n";
    message += _espserver.arg("plain");
    message += "\n";
    _espserver.send(200, "text/plain", "Body received!");
    Serial.println(message);
  });
  _espserver.begin();
}

void WifiServer::runServer()
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
  ArduinoCommunicator(SoftwareSerial* arduinoserial);
  void beginSerial(int baud);
  private:
  SoftwareSerial* _arduinoserial;
};

ArduinoCommunicator::ArduinoCommunicator(SoftwareSerial* arduinoserial)
{
  _arduinoserial = arduinoserial;
}

void ArduinoCommunicator::beginSerial(int baud)
{
  _arduinoserial->begin(baud);
}

class POSTReceiver
{
  public:
  POSTReceiver(WifiServer server);
  void receivePost();
  private:
  WifiServer _server;
};

void POSTReceiver::receivePost()
{
  /*if (_server.hasArg("plain"))
  {
    _server.send(400, "text/plain", "Body not received!")  
  }  
  else
  {
    Serial.println("Body:" + server.arg("plain"));
    _server.send(200, "text/plain", "Body received!");
  }*/
}

WifiConnection connection(SECRET_SSID, SECRET_PASSWORD);
WifiServer server(80);
MDNSHandler mdns;

void setup()
{
  Serial.begin(115200);
  connection.wifiConnect();
  server.startServer();
  mdns.startResponder("VendingMachineAPI");
}

void loop()
{
  server.Update();
}
