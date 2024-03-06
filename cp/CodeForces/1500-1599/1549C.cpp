#include <bits/stdc++.h>
using namespace std;
#define fr front
#define bk back
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
#define ll long long
#define ld long double
#define rep(i, x, y) for (ll i = x; i < y; i++)
#define rrep(i, x, y) for (ll i = x; i >= y; i--)
#define debug_stl(x)      \
    for (auto i : x)      \
    {                     \
        cout << i << " "; \
    }                     \
    cout << endl;
#define debug_1d(x, a, b)                 \
    rep(i, a, b) { cout << x[i] << " "; } \
    cout << endl;
#define debug_2d(x, a1, b1, a2, b2)                \
    rep(i, a1, b1)                                 \
    {                                              \
        rep(j, a2, b2) { cout << x[i][j] << " "; } \
        cout << endl;                              \
    }
#define all(x) x.begin(), x.end()
#define MOD (ll)(1e9 + 7)
#define INF8 (ll)(1e17 + 5)
#define endl '\n'
typedef vector<ll> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<vector<ll>> VVI;
typedef pair<ll, ll> PI;
typedef pair<ll, PI> PPI;
typedef vector<PI> VP;
typedef vector<PPI> VPP;
vector<ll> primeList;
vector<bool> primes;
ll mod(ll x)
{
    return (x % MOD + MOD) % MOD;
}
ll power(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = mod(res * x);
        y >>= 1;
        x = mod(x * x);
    }
    return res;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}
void sieve()
{
    primes[0] = false;
    primes[1] = false;
    for (ll i = 2; i < primes.size(); i++)
        primes[i] = true;
    for (ll i = 2; i * i < primes.size(); i++)
    {
        if (primes[i])
        {
            for (ll j = i * i; j < primes.size(); j += i)
                primes[j] = false;
        }
    }
    for (ll i = 2; i < primes.size(); i++)
    {
        if (primes[i])
            primeList.push_back(i);
    }
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}