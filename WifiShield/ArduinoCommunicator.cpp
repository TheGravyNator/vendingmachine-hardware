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

void ArduinoCommunicator::setDispensingIndicator(DispensingIndicator* dispensing)
{
  _dispensing = dispensing;
}

void ArduinoCommunicator::sendOrder(SodaRequest order)
{
  _arduinocomm->println(order.slot + ":" + order.soda_amount);
}
