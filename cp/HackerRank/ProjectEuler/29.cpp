#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXN = 3e6 + 100;

int mark[MAXN];

ll a[50];

int main()
{
    int n;
    scanf("%d", &n);
    int x = log2(n * 1.0);
    for (int i = 1; i <= x; i++)
    {
        ll sum = 0, t = 2 * i;
        for (int j = 1; j < n; j++)
        {
            if (!mark[t])
            {
                sum++;
                mark[t] = 1;
            }
            t = t + i;
        }
        a[i] = sum;
    }
    memset(mark, 0, sizeof mark);
    ll ans = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (!mark[i])
        {
            double t = log(n * 1.0) / log(i * 1.0);
            int tt = (int)(t + 0.00001);
            for (ll j = 1; j <= tt; j++)
                ans += a[j];
            for (ll j = i * i; j <= n; j = j * i)
                mark[j] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
