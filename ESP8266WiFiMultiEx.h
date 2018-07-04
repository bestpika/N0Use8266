#ifndef ESP8266WIFIMULTIEX_H
#define ESP8266WIFIMULTIEX_H

#include "ESP8266WiFiMulti.h"

class ESP8266WiFiMultiEx : public ESP8266WiFiMulti
{
public:
  void addAPs(String ssid, String pass);
  void addAPs(std::vector<std::pair<String, String>> info);
};

#endif
