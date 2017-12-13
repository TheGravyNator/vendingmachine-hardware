#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay
{
  public:
  Relay(int pin);
  void init();
  void trigger(int delay_amount);
  private:
  int _pin;
};

#endif
