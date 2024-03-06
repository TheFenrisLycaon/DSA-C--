#include <iostream>
#include <vector>
int main()
{
  const unsigned int MaxNumber = 1000;
  std::vector<unsigned long long> combinations(MaxNumber + 1, 0);
  combinations[0] = 1;
  std::vector<unsigned int> primes;
  for (unsigned int i = 2; i <= MaxNumber; i++)
  {
    bool isPrime = true;
    for (auto p : primes)
    {
      if (p*p > i)
        break;
      if (i % p == 0)
      {
        isPrime = false;
        break;
      }
    }
    if (!isPrime)
      continue;
    primes.push_back(i);
    for (unsigned int pos = 0; pos <= MaxNumber - i; pos++)
      combinations[pos + i] += combinations[pos];
  }
#ifdef ORIGINAL
  for (size_t i = 0; i < combinations.size(); i++)
    if (combinations[i] > 5000)
    {
      std::cout << i << std::endl;
      break;
    }
#else
  unsigned int tests = 1;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int n;
    std::cin >> n;
    std::cout << combinations[n] << std::endl;
  }
#endif
  return 0;
}