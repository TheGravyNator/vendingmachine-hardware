#include "Arduino.h"
#include "ShieldCommunicator.h"
#include "SodaRequest.h"
#include <SoftwareSerial.h>

ShieldCommunicator::ShieldCommunicator()
{
  _shieldcomm = NULL;
}

void ShieldCommunicator::beginSerial(SoftwareSerial* serial, int baud)
{
  _shieldcomm = serial;
  _shieldcomm->begin(baud);
}

struct SodaRequest ShieldCommunicator::receiveOrder()
{
  struct SodaRequest request; 
  while (_shieldcomm->available() > 0)
  {
    request.soda_type = _shieldcomm->readStringUntil(':');
    _shieldcomm->read();
    request.soda_amount = _shieldcomm->readStringUntil('\n').toInt();
  }
  return request;
}
