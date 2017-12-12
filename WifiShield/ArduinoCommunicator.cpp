#include "Arduino.h"
#include "ArduinoCommunicator.h"
#include <SoftwareSerial.h>

ArduinoCommunicator::ArduinoCommunicator()
{
  _arduinocomm = NULL;
}

void ArduinoCommunicator::beginSerial(SoftwareSerial* serial, int baud)
{
  _arduinocomm = serial;
  _arduinocomm->begin(baud);
}

void ArduinoCommunicator::sendOrder(String message)
{
  _arduinocomm->println(message);
  Serial.println(message);
}
