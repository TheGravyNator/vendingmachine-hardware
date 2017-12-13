#include "Arduino.h"
#include "RelayHiLo.h"

RelayHiLo::RelayHiLo(int pin_hi, int pin_lo)
{
  _pin_hi = pin_hi;
  _pin_lo = pin_lo;
}

