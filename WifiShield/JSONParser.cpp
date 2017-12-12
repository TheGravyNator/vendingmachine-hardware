#include "Arduino.h"
#include "JSONParser.h"
#include "SodaRequest.h"
#include <ArduinoJson.h>

struct SodaRequest JSONParser::parseJSON(String json_string)
{
  StaticJsonBuffer<200> newBuffer;
  JsonObject& newjson = newBuffer.parseObject(json_string);
  struct SodaRequest request;
  const char* soda_type = newjson["soda_type"];
  request.soda_type = String(soda_type);
  request.soda_amount = newjson["soda_amount"];
  return request;
}
