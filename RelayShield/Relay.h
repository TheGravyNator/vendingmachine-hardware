#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay
{
  public:
  Relay(int pin);
  void init();
  void trigger(int delay_amount_up, int delay_amount_down);
  private:
  int _pin;
};

#endif
