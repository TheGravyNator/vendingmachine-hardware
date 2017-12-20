#ifndef DispensingIndicator_h
#define DispensingIndicator_h

#include "Arduino.h"

class DispensingIndicator
{
  public:
  DispensingIndicator(int pin);
  void init();
  bool getIndicator();
  private:  
  int _pin;
};

#endif
