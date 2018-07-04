#include "ESP8266WiFiMultiEx.h"

void ESP8266WiFiMultiEx::addAPs(String ssid, String pass)
{
  char d = ';'; // 分隔符號
  int ssidFo = 0;
  int ssidTo = 0;
  int passFo = 0;
  int passTo = 0;
  do
  {
    // 取得分隔符號位置
    ssidTo = ssid.indexOf(d, ssidFo);
    passTo = pass.indexOf(d, passFo);
    // 取得部分字串
    String _ssid = ssid.substring(ssidFo, ssidTo);
    String _pass = pass.substring(passFo, passTo);
    // 加入連線資訊
    ESP8266WiFiMulti::addAP(_ssid.c_str(), _pass.c_str());
    // 移動位置
    ssidFo = ssidTo + 1;
    passFo = passTo + 1;
  } while (ssidTo >= 0 && passTo >= 0);
}

void ESP8266WiFiMultiEx::addAPs(std::vector<std::pair<String, String>> info)
{
  for (int i = 0; i < info.size(); i++)
  {
    std::pair<String, String> _info = info.at(i);
    const char *ssid = _info.first.c_str();
    const char *pass = _info.second.c_str();
    ESP8266WiFiMulti::addAP(ssid, pass);
  }
}
