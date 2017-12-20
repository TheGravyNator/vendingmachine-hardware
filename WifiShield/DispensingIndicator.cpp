#include "Arduino.h"
#include "DispensingIndicator.h"

DispensingIndicator::DispensingIndicator(int pin)
{
  _pin = pin;
}

void DispensingIndicator::init()
{
  pinMode(_pin, INPUT);
  digitalWrite(_pin, LOW);  
}

bool DispensingIndicator::getIndicator()
{
  if(digitalRead(_pin) == HIGH)
  {
    return true;
  }
  if(digitalRead(_pin) == LOW)
  {
    return false;  
  }
}
