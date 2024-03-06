#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPrime(ll n)
{
    if (n <= 1)
        return false;

    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll f, p1, p2, res1, res2;
    cin >> f >> p1 >> p2;
    bool flag = false;
    unordered_map<ll, bool> mp;
    for (ll i = p1; i <= p2; i++)
    {
        if (isPrime(i))
            mp[i] = true;
        else
            mp[i] = false;
    }
    for (ll i = p1; i <= p2 - 1; i++)
    {
        if (!mp[i])
        {
            for (ll j = i + 1; j <= p2; j++)
            {
                if (!mp[j])
                {
                    double temp = ((i * j) / ((j - i) * (j - i)));
                    if (temp > f)
                    {
                        res1 = i;
                        res2 = j;
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }
    }
    if (flag)
        cout << res1 << " " << res2;
    else
        cout << "None";
    return 0;
}