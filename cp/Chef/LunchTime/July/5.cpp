#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t, n, k, s, i;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int size = 0, sum = 0;
        for (i = 0; i <= n; i++)
        {
            sum += a[i];
            if (sum / k >= s)
            {
                break;
            }
            size++;
        }
        cout << size << endl;
    }
    return 0;
}
