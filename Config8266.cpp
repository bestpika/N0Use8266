#include "Config8266.h"

Config8266::Config8266() : fileName("config.json")
{
  SPIFFS.begin();
}

bool Config8266::init()
{
  File file = SPIFFS.open(fileName, "r");
  if (!file)
  {
    save(); // 產生一個空的檔案
  }
  else
  {
    file.close();
    load();
  }
  print();
  return true;
}

bool Config8266::load()
{
  File file = SPIFFS.open(fileName, "r");
  deserializeJson(doc, file);
  root = doc.as<JsonObject>();
  file.close();
  return true;
}

void Config8266::print()
{
  serializeJsonPretty(root, Serial);
  Serial.println();
}

bool Config8266::reset()
{
  SPIFFS.remove(fileName);
  return init();
}

bool Config8266::save()
{
  File file = SPIFFS.open(fileName, "w");
  root = doc.to<JsonObject>();
  serializeJson(root, file);
  file.close();
  return true;
}
