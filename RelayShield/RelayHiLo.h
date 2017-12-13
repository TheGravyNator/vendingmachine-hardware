#ifndef RelayHiLo_h
#define RelayHiLo_h

#include "Arduino.h"

class RelayHiLo
{
  public:
  RelayHiLo(int pin_hi, int pin_lo);
  private:
  int _pin_hi;
  int _pin_lo;
};

#endif
