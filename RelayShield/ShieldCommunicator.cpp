#include "Arduino.h"
#include "ShieldCommunicator.h"
#include "SodaRequest.h"
#include <SoftwareSerial.h>

ShieldCommunicator::ShieldCommunicator()
{
  _shieldcomm = NULL;
}

