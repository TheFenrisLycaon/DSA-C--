#include <vector>
#include <iostream>
struct BigNum : public std::vector<unsigned int>
{
  static const unsigned int MaxDigit = 10;
  BigNum(unsigned long long x = 0)
  {
    do
    {
      push_back(x % MaxDigit);
      x /= MaxDigit;
    } while (x > 0);
  }
  BigNum operator*(unsigned int factor) const
  {
    unsigned long long carry = 0;
    auto result = *this;
    for (auto &i : result)
    {
      carry += i * (unsigned long long)factor;
      i = carry % MaxDigit;
      carry /= MaxDigit;
    }
    while (carry > 0)
    {
      result.push_back(carry % MaxDigit);
      carry /= MaxDigit;
    }
    return result;
  }
};
int main()
{
  unsigned int maximum = 100;
  std::cin >> maximum;
  unsigned int maxSum = 1;
  for (unsigned int base = 1; base <= maximum; base++)
  {
    BigNum power = 1;
    for (unsigned int exponent = 1; exponent <= maximum; exponent++)
    {
      unsigned int sum = 0;
      for (auto digit : power)
        sum += digit;
      if (maxSum < sum)
        maxSum = sum;
      power = power * base;
    }
  }
  std::cout << maxSum << std::endl;
  return 0;
}
