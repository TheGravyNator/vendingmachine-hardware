#include "Arduino.h"
#include "ArduinoCommunicator.h"
#include "SodaRequest.h"
#include "DispensingIndicator.h"
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

{
  _arduinocomm->println(message);
  Serial.println(message);
void ArduinoCommunicator::sendOrder(SodaRequest order)
{
  _arduinocomm->println(order.soda_type + ":" + order.soda_amount);
}
