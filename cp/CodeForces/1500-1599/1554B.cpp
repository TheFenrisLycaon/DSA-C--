#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define fill(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define ll long long int
int main()
{
#ifdef OJ
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
    ll test;
    cin >> test;
    while (test--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n], res;
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        ll ans = (1 * 2) - k * (arr[0] | arr[1]);
        for (ll j = 1; j < n; j++)
        {
            for (ll i = 0; i < j; i++)
            {
                res = (i + 1) * (j + 1) - k * (arr[i] | arr[j]);
                ans = max(ans, res);
            }
        }
        cout << ans << endl;
    }
    return 0;
}