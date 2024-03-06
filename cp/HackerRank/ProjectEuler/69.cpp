#include <iostream>
int main()
{
  const unsigned int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 57 };
  unsigned int tts;
  std::cin >> tts;
  while (tts--)
  {
    unsigned long long lim;
    std::cin >> lim;
    unsigned long long bestPosition = 1;
    for (auto p : primes)
    {
      if (bestPosition >= (lim + p - 1) / p)
        break;
      bestPosition *= p;
    }
    std::cout << bestPosition << std::endl;
  }
  return 0;
}