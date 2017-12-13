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

