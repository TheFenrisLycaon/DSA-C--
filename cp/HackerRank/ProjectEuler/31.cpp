#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#define tr(container, it) \
    for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

int main()
{
    int coin[] = {1, 2, 5, 10, 20, 50, 100, 200};
    long long MOD = 1000000000 + 7;
    vector<long long> dp(100007, 0);
    dp[0] = 1;
    for (int c = 0; c < 8; c++)
    {
        for (long long v = coin[c]; v < 100007; v++)
            dp[v] = (dp[v] + dp[v - coin[c]]) % MOD;
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        long long N = 10;
        cin >> N;
        cout << dp[N] << endl;
    }
    return 0;
}
