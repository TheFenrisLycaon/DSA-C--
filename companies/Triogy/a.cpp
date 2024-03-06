
#include <bits/stdc++.h>

using namespace std;

int main()

{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);
  int x = 1;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] % x == 0)
    {
      ans += a[i] / x;
    }
    else
    {
      ans += (a[i] + x) / x;
    }

    x++;
  }
  cout << ans << endl;
}