#ifndef JSONParser_h
#define JSONParser_h

#include "Arduino.h"
#include "SodaRequest.h"
#include <ArduinoJson.h>

class JSONParser
{
  public: 
  struct SodaRequest parseJSON(String json_string); 
};

#endif
