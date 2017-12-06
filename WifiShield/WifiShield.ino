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
#include "WifiConnection.h"
#include "MDNSHandler.h"

WifiConnection connection(SECRET_SSID, SECRET_PASSWORD);
WifiServer server(80);
MDNSHandler mdns;
ArduinoCommunicator arduinocomm(new SoftwareSerial(13, 12));

void setup()
{
  Serial.begin(115200);
  arduinocomm.beginSerial(115200);
  connection.wifiConnect();
  server.startServer();
  mdns.startResponder("VendingMachineAPI");
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    connection.wifiConnect();  
  }
  else
  {
    server.runServer();
  }
}
