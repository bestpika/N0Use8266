#ifndef N0USE8266_H
#define N0USE8266_H

#include <ctime>
#include <tuple>
#include <vector>
#include "Arduino.h"

class N0Use8266
{
public:
  static String decodeUri(String s);
  static int getCks(std::vector<byte> *data, int startIdx, int endedIdx);
  static String getDateTimeStr();
  static unsigned char hex2Int(char c);
  static std::tuple<uint8_t, uint8_t, uint8_t> HSV2RGB(uint16_t H, uint16_t S, uint16_t V);
  static std::pair<String, String> parseCmd(String msg);
  static void reboot();
  static std::vector<String> stringSplit(String input, char ch);
};

#endif
