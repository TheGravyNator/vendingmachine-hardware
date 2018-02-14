#include "Arduino.h"
#include "StockCheck.h"

bool StockCheck::isEmpty(String slot)
{
  if(slot == "slot_1")
  {
      if(digitalRead(SLOT_1_STOCK) == HIGH)
      {
        return true;  
      }
  }
  else if(slot == "slot_2")
  {
      if(digitalRead(SLOT_2_STOCK) == HIGH)
      {
        return true;  
      }
  }
  else if(slot == "slot_3")
  {
      if(digitalRead(SLOT_3_STOCK) == HIGH)
      {
        return true;  
      }
  }
  else if(slot == "slot_4")
  {
      if(digitalRead(SLOT_4_STOCK) == HIGH)
      {
        return true;  
      }
  }
  else if(slot == "slot_5")
  {
      if(digitalRead(SLOT_5_STOCK) == HIGH)
      {
        return true;  
      }
  }
  else
  {
    return false;  
  }
}
