#include <cmath>
#include <vector>
#include <iostream>

unsigned int combinations(unsigned int a, unsigned int b_c)
{
  if (2*a < b_c)
    return 0;
  if (a >= b_c)
    return b_c / 2;
  return a - (b_c - 1) / 2; 
}

unsigned long long countSingle(unsigned int a)
{
  unsigned long long sum = 0;
  for (unsigned int b_c = 1; b_c <= 2 * a; b_c++)
  {
    auto diagonalSquared = a * a + b_c * b_c;
    unsigned int root = sqrt(diagonalSquared);
    if (root * root == diagonalSquared)
      sum += combinations(a, b_c);
  }
  return sum;
}

unsigned int gcd(unsigned int x, unsigned int y)
{
  while (x != 0)
  {
    auto temp = x;
    x = y % x;
    y = temp;
  }
  return y;
}

std::vector<unsigned long long> countAll(unsigned int limit)
{
  std::vector<unsigned long long> solutions(limit + 1, 0);
  for (unsigned int m = 1; m <= sqrt(2*limit); m++)
    for (unsigned int n = 1; n < m; n++)
    {
      if (m % 2 == n % 2) 
        continue;         
      if (gcd(m, n) != 1)
        continue;
      auto x = m*m - n*n;
      auto y = 2*m*n;
      for (unsigned int k = 1; k*x <= limit; k++)
        solutions[k*x] += combinations(k*x, k*y);
      for (unsigned int k = 1; k*y <= limit; k++)
        solutions[k*y] += combinations(k*y, k*x);
    }
  return solutions;
}

int main()
{
#ifdef ORIGINAL
  unsigned int sum = 0;
  unsigned int a   = 0;
  while (sum <= 1000000)
    sum += countSingle(++a);
  std::cout << a << std::endl;
#else
  auto solutions = countAll(1000000);
  std::vector<unsigned long long> total;
  unsigned long long sum = 0;
  for (auto i : solutions)
  {
    sum += i;
    total.push_back(sum);
  }
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int maxA;
    std::cin >> maxA;
    std::cout << total[maxA] << std::endl;
  }
#endif
  return 0;
}
