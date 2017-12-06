#include "Arduino.h"
#include "WifiConnection.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

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
