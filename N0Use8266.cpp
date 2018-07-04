#include "N0Use8266.h"

String N0Use8266::decodeUri(String s)
{
  String a = "";
  char c;
  std::pair<char, char> h;
  for (int i = 0; i < s.length(); i++)
  {
    c = s.charAt(i);
    if (c == '+')
    {
      a += ' ';
    }
    else if (c == '%')
    {
      h.first = s.charAt(++i);
      h.second = s.charAt(++i);
      c = (hex2Int(h.first) << 4) | hex2Int(h.second);
      a += c;
    }
    else
    {
      a += c;
    }
    yield();
  }
  return a;
}

unsigned char N0Use8266::hex2Int(char c)
{
  if ('0' <= c && c <= '9')
  {
    return ((unsigned char)c - '0');
  }
  else if ('a' <= c && c <= 'f')
  {
    return ((unsigned char)c - 'a' + 10);
  }
  else if ('A' <= c && c <= 'F')
  {
    return ((unsigned char)c - 'A' + 10);
  }
  else
  {
    return 0;
  }
}

std::tuple<uint8_t, uint8_t, uint8_t> N0Use8266::HSV2RGB(uint16_t H, uint16_t S, uint16_t V)
{
  double h = H % 361,
         s = S % 101 / 100.0,
         v = V % 101 / 100.0; // limit
  uint8_t i, p, q, t, r, g, b;
  double f;
  if (S % 100 == 0)
  {
    r = g = b = (v * 255);
  }
  else
  {
    i = h / 60.0;
    f = h / 60.0 - i;
    p = v * (1.0 - s) * 255.0;
    q = v * (1.0 - f * s) * 255.0;
    t = v * (1.0 - (1.0 - f) * s) * 255.0;
    switch (i)
    {
    case 0:
      r = v;
      g = t;
      b = p;
      break;
    case 1:
      r = q;
      g = v;
      b = p;
      break;
    case 2:
      r = p;
      g = v;
      b = t;
      break;
    case 3:
      r = p;
      g = q;
      b = v;
      break;
    case 4:
      r = t;
      g = p;
      b = v;
      break;
    case 5:
      r = v;
      g = p;
      b = q;
      break;
    }
  }
  return std::make_tuple(r, g, b);
}

String N0Use8266::getDateTimeStr()
{
  time_t timeNow = time(nullptr);
  tm *dateTime = localtime(&timeNow);
  String dateTimeStr = asctime(dateTime);
  dateTimeStr.replace("\n", "");
  return dateTimeStr;
}

std::pair<String, String> N0Use8266::parseCmd(String msg)
{
  std::pair<String, String> cmd;
  char d = '=';
  int msgTo = 0;
  msgTo = msg.indexOf(d, 0);
  String cmdName = msg.substring(0, msgTo);
  String cmdValue = msg.substring(msgTo + 1);
  if (!cmdName.equalsIgnoreCase(cmdValue))
  {
    cmd.first = cmdName;
    cmd.second = cmdValue;
  }
  return cmd;
}

void N0Use8266::reboot()
{
  delay(5000);
  ESP.reset();
}

std::vector<String> N0Use8266::stringSplit(String input, char ch)
{
  std::vector<String> ans;
  int fo = 0;
  int to = 0;
  do
  {
    to = input.indexOf(ch, fo);
    String _input = input.substring(fo, to);
    ans.push_back(_input);
    fo = to + 1;
  } while (to >= 0);
  return ans;
}
