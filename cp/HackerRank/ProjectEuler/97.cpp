#include <iostream>
#include <iomanip>

typedef unsigned __int128 BigNum;
const unsigned int Digits = 12;
const BigNum       Modulo = 1000000000000ULL;

BigNum powmod(BigNum base, unsigned int exponent, BigNum modulo)
{
  BigNum result = 1;
  while (exponent > 0)
  {
    if (exponent & 1)
      result = (result * base) % modulo;
    base = (base * base) % modulo;
    exponent >>= 1;
  }
  return result;
}

int main()
{
  unsigned long long sum = 0;
  unsigned int tests = 1;
  std::cin >> tests;
  while (tests--)
  {
    unsigned long long factor, base, exponent, add;
    std::cin >> factor >> base >> exponent >> add;
    unsigned long long result = (powmod(base, exponent, Modulo) * factor + add) % Modulo;
    sum += result;
    sum %= Modulo;
  }
  std::cout << std::setfill('0') << std::setw(Digits) << sum;
  return 0;
}