#include "Arduino.h"
#include "Relay.h"

Relay::Relay(int pin)
{
  _pin = pin;
}

void Relay::init()
{
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
}

