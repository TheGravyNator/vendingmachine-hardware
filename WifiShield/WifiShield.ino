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
#include "QueueList.h"
#include "Constants.h"

QueueList <struct SodaRequest> queue;

WifiConnection connection(SECRET_SSID, SECRET_PASSWORD);
JSONParser jsonparser;
ArduinoCommunicator arduinocomm;
WifiServer server(SERVER_PORT, jsonparser, &queue);
MDNSHandler mdns;

void setup()
{
  Serial.begin(BAUD_RATE);
  arduinocomm.beginSerial(new SoftwareSerial(RX_SERIAL, TX_SERIAL), BAUD_RATE);
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
    if(dispensing.getIndicator() == false)
    {
      if(!queue.isEmpty())
      {
        delay(10);
        struct SodaRequest queueorder = queue.pop(); 
        arduinocomm.sendOrder(queueorder);
      }
    }
  }
}
