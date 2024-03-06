#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
typedef std::vector<unsigned int> BigNumber;
std::map<BigNumber, unsigned int> finalNumber;
bool isLychrel(unsigned int x, unsigned int maxIterations)
{
  BigNumber number;
  while (x > 0)
  {
    number.push_back(x % 10);
    x /= 10;
  }
  for (unsigned int iteration = 0; iteration < maxIterations; iteration++)
  {
    auto reverse = number;
    std::reverse(reverse.begin(), reverse.end());
#ifdef ORIGINAL
    if (iteration > 0) 
#endif
    if (number == reverse)
    {
      finalNumber[number]++;
      return false;
    }
    auto sum = number;
    unsigned int carry = 0;
    for (size_t digit = 0; digit < number.size(); digit++)
    {
      sum[digit] += reverse[digit] + carry;
      if (sum[digit] >= 10)
      {
        sum[digit] -= 10;
        carry = 1;
      }
      else
      {
        carry = 0;
      }
    }
    if (carry > 0)
      sum.push_back(carry);
    number = std::move(sum);
  }
  return true;
}
int main()
{
#ifdef ORIGINAL
  unsigned int iterations = 50;
#else
  unsigned int iterations = 60;
#endif
  unsigned int maxNumber = 10000;
  std::cin >> maxNumber;
  unsigned int count = 0;
  for (unsigned int i = 0; i <= maxNumber; i++)
    if (isLychrel(i, iterations))
      count++;
#ifdef ORIGINAL
  std::cout << count << std::endl;
#else
  unsigned int bestCount = 0;
  BigNumber    bestNumber;
  for (auto f : finalNumber)
    if (bestCount < f.second)
    {
      bestCount  = f.second;
      bestNumber = f.first;
    }
  std::reverse(bestNumber.begin(), bestNumber.end());
  for (auto digit : bestNumber)
    std::cout << digit;
  std::cout << " " << bestCount << std::endl;
#endif
  return 0;
}
