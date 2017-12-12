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
#include "WifiConnection.h"
#include "MDNSHandler.h"
#include "ArduinoCommunicator.h"
#include "WifiServer.h"
#include "JSONParser.h"

WifiConnection connection(SECRET_SSID, SECRET_PASSWORD);
JSONParser jsonparser;
ArduinoCommunicator arduinocomm;
WifiServer server(80, jsonparser);
MDNSHandler mdns;

void setup()
{
  Serial.begin(115200);
  arduinocomm.beginSerial(new SoftwareSerial(13, 12), 115200);
  connection.wifiConnect();
  server.setArduinoCommunicator(arduinocomm);
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
