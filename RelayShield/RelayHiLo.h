#ifndef RelayHiLo_h
#define RelayHiLo_h

#include "Arduino.h"

class RelayHiLo
{
  public:
  RelayHiLo(int pin_hi, int pin_lo);
  void init();
  void trigger(int delay_amount_up, int delay_amount_down);
  private:
  int _pin_hi;
  int _pin_lo;
};

#endif
