#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef unsigned long long ull;
typedef long double lld;
int solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int k;
    cin >> k;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1)
        {
            int x = a[i] - 1;
            int y = b[i] - 1;
            int z = x / y;
            if (x % y)
            {
                z++;
            }
            c[i] = 2 * z - 1;
        }
        else
        {
            int x = a[i] - 2;
            int y = b[i] - 2;
            int z = x / y;
            if (x % y)
            {
                z++;
            }
            c[i] = 2 * z - 1;
        }
        A[i] = c[i];
    }
    vector<int> v;
    build(1, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i + k - 1 >= n)
            break;
        v.pb(query(1, 0, n - 1, i, i + k - 1));
    }
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
int main()
{
    solve();
    return 0;
}
