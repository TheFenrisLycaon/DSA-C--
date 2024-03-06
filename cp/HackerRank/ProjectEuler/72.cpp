#include <iostream>
#include <vector>
int main()
{
  unsigned int lim = 1000000;
  std::vector<unsigned int> phi(lim + 1); 
  for (size_t i = 0; i < phi.size(); i++)
    phi[i] = i;
  for (unsigned int i = 2; i <= lim; i++)
  {
    if (phi[i] == i)
      for (unsigned int k = 1; k * i <= lim; k++)
        phi[k * i] -= phi[k * i] / i;
  }
  std::vector<unsigned long long> sums(phi.size(), 0);
  for (unsigned int i = 2; i <= lim; i++)
    sums[i] = sums[i - 1] + phi[i];
  unsigned int tests = 1;
  std::cin >> tests;
  while (tests--)
  {
    std::cin >> lim;
    std::cout << sums[lim] << std::endl;
  }
}