#include <iostream>
#include <vector>
int main()
{
  std::vector<unsigned long long> partitions;
  partitions.push_back(1);
#ifdef ORIGINAL
  const long long modulo =    1000000; 
#else
  const long long modulo = 1000000007; 
  unsigned int tests = 1;
  std::cin >> tests;
  while (tests--)
#endif
  {
    unsigned int limit = 100000; 
#ifndef ORIGINAL
    std::cin >> limit;
#endif
    for (unsigned int n = partitions.size(); n <= limit; n++)
    {
      long long sum = 0;
      for (unsigned int i = 0; ; i++) 
      {
        int alternate = 1 + (i / 2); 
        if (i % 2 == 1)
          alternate = -alternate;    
        unsigned int offset = alternate * (3 * alternate - 1) / 2;
        if (n < offset)
          break;
        if (i % 4 < 2)
          sum += partitions[n - offset]; 
        else
          sum -= partitions[n - offset]; 
        sum %= modulo;
      }
      if (sum < 0)
        sum += modulo;
#ifdef ORIGINAL
      if (sum == 0)
        break;
#endif
      partitions.push_back(sum);
    }
#ifdef ORIGINAL
    std::cout << partitions.size() << std::endl;
#else
    std::cout << partitions[limit] << std::endl;
#endif
  }
  return 0;
}