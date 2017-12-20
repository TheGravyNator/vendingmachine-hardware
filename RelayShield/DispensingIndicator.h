#ifndef DispensingIndicator_h
#define DispensingIndicator_h

#include "Arduino.h"

class DispensingIndicator
{
  public:
  DispensingIndicator(int pin, bool state);
  void init();
  void setIndicator(bool state);
  bool getIndicator();
  private:  
  int _pin;
  bool _state;
};

#endif
