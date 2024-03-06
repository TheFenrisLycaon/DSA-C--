#include <iostream>
template <typename T>
void multiply(T a, T b, T& resH, T& resL)
{
  const T Shift = 4 * sizeof(a);
  const T Mask  = T(~0) >> Shift;
  auto a_high = a >> Shift;
  auto a_low  = a &  Mask;
  auto b_high = b >> Shift;
  auto b_low  = b &  Mask;
  auto c_0  = a_low  * b_low;
  auto c_1a = a_high * b_low;
  auto c_1b = a_low  * b_high;
  auto c_2  = a_high * b_high;
  auto k = ((c_0 >> Shift) + (c_1a & Mask) + (c_1b & Mask)) >> Shift;
  resH = c_2 + (c_1a >> Shift) + (c_1b >> Shift) + k;
  resL  = c_0 + (c_1a << Shift) + (c_1b << Shift);
}
bool isLess(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d)
{
  unsigned long long r1H, r1L;
  unsigned long long r2H, r2L;
  multiply(a, d, r1H, r1L);
  multiply(c, b, r2H, r2L);
  if (r1H < r2H)
    return true;
  if (r1H > r2H)
    return false;
  return (r1L < r2L);
}
int main()
{
  unsigned int tts = 1;
  std::cin >> tts;
  while (tts--)
  {
    unsigned int a = 3;
    unsigned int b = 7;
    unsigned long long lim = 1000000;
    std::cin >> a >> b >> lim;
    unsigned long long leftN  = 0;
    unsigned long long leftD  = 1;
    unsigned long long rightN = 1;
    unsigned long long rightD = 1;
    while (leftD + rightD <= lim)
    {
      auto mediantN = leftN + rightN;
      auto mediantD = leftD + rightD;
      if (isLess(mediantN, mediantD, a, b))
      {
        leftN = mediantN;
        leftD = mediantD;
      }
      else
      {
        rightN = mediantN;
        rightD = mediantD;
        if (rightN == a && rightD == b)
          break;
      }
    }
    if (lim >= leftD + rightD)
    {
      auto difference = lim - (leftD + rightD);
      auto repeat = 1 + difference / rightD;
      leftN += repeat * rightN;
      leftD += repeat * rightD;
    }
    std::cout << leftN << " " << leftD << std::endl;
  }
  return 0;
}