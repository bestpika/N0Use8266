#ifndef CONFIG8266_H
#define CONFIG8266_H

#include "FS.h"
#include "ArduinoJson.h"

class Config8266
{
protected:
  const String fileName;
  DynamicJsonDocument doc;

public:
  JsonObject root;

public:
  Config8266();
  bool init();
  bool load();
  void print();
  bool reset();
  bool save();
};

#endif
