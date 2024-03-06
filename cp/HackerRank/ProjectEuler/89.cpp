#include <iostream>
#include <string>

unsigned int roman2number(const std::string& roman)
{
  unsigned int result = 0;
  unsigned int last = 0;
  bool subtract = false;
  for (auto i = roman.rbegin(); i != roman.rend(); i++)
  {
    unsigned int current = 0;
    switch (*i)
    {
    case 'M': current = 1000; break;
    case 'D': current =  500; break;
    case 'C': current =  100; break;
    case 'L': current =   50; break;
    case 'X': current =   10; break;
    case 'V': current =    5; break;
    case 'I': current =    1; break;
    }
    if (current < last)
    {
      subtract = true;
      last = current;
    }
    else if (current > last)
    {
      subtract = false;
      last = current;
    }
    if (subtract)
      result -= current;
    else
      result += current;
  }
  return result;
}

std::string number2roman(unsigned int number)
{
  const unsigned int NumRules = 13;
  const unsigned int rules[NumRules] =
    { 1000,  900, 500,  400, 100,  90,   50,   40,  10,    9,   5,    4,  1  };
  const char* action[NumRules] =
    {  "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
  std::string result;
  for (unsigned int i = 0; i < NumRules; i++)
    while (number >= rules[i])
    {
      number -= rules[i];
      result += action[i];
    }
  return result;
}

int main()
{
  unsigned int saved = 0;
  unsigned int tests = 1000;
#ifndef ORIGINAL
  std::cin >> tests;
#endif
  while (tests--)
  {
    std::string roman;
    std::cin >> roman;
    auto number    = roman2number(roman);
    auto optimized = number2roman(number);
    saved += roman.size() - optimized.size();
#ifndef ORIGINAL
    std::cout << optimized << std::endl;
#endif
  }
#ifdef ORIGINAL
  std::cout << saved << std::endl;
#endif
  return 0;
}