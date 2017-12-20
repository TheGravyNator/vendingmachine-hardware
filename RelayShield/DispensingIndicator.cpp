#include "Arduino.h"
#include "DispensingIndicator.h"

DispensingIndicator::DispensingIndicator(int pin, bool state)
{
  _pin = pin;
  _state = state;
}

void DispensingIndicator::init()
{
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);  
}

void DispensingIndicator::setIndicator(bool state)
{
  if(state == true)
  {
    digitalWrite(_pin, HIGH);
    _state = state;
  }  
  if(state == false)
  {
    digitalWrite(_pin, LOW);
    _state = state; 
  }
}

bool DispensingIndicator::getIndicator()
{
  return _state;
}
