#include "Arduino.h"
#include "JSONParser.h"
#include "SodaRequest.h"
#include <ArduinoJson.h>

struct SodaRequest JSONParser::parseJSON(String json_string)
{
  StaticJsonBuffer<200> newBuffer;
  JsonObject& newjson = newBuffer.parseObject(json_string);
  struct SodaRequest request;
  const char* slot = newjson["slot"];
  request.slot = slot;
  request.soda_amount = newjson["soda_amount"];
  return request;
}
