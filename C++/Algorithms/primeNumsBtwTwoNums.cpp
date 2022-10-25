#include <iostream>
#include <math.h>
using namespace std;

bool prime(int n)
{
  if (n == 0 || n == 1)
    return false;
  int i;
  for (i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;

  return true;
}
int main()
{
  int a, b;
  cin >> a >> b;
  cout << "The prime numbers are : \n";
  for (int i = a; i < b; i++)
  {
    if (prime(i))
    {
      cout << i << endl;
    }
  }
  return 0;
}