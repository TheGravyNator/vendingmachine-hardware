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

void Relay::trigger(int delay_amount)
{
  digitalWrite(_pin, HIGH);
  delay(delay_amount);
  digitalWrite(_pin, LOW);
  delay(delay_amount);
}
