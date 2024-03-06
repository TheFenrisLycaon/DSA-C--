#include <bits/stdc++.h>
#define mod 1000000007
#define lli long long int
#define ll long long
#define pll pair<long long, long long>
#define INF 1000000000;
#define el '\n'
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
#define garr(i, n) for (ll i = 0; i < (n); i++)
#define parr(i, n, arr)          \
    for (ll i = 0; i < (n); i++) \
        cout << arr[i] << " ";
using namespace std;
int dp[1001][1001];
int dfs(vector<int> &arr, int ind, int h, int k, int n, vector<int> tempor)
{
    if (ind >= n)
    {
        return tempor.size();
    }
    if (dp[ind][tempor.size()] != -1)
    {
        return dp[h][tempor.size()];
    }
    int ans;
    if (tempor.back() != arr[ind])
    {
        ans = (dfs(arr, ind + 1, h, k, n, tempor));
        if (h < k)
        {
            tempor.push_back(arr[ind]);
            ans = max(ans, dfs(arr, ind + 1, h + 1, k, n, tempor));
        }
    }
    else
    {
        tempor.push_back(arr[ind]);
        ans = dfs(arr, ind + 1, h, k, n, tempor);
    }
    return dp[h][tempor.size()] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int it;
            cin >> it;
            arr.push_back(it);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> tempor;
            tempor.push_back(arr[i]);
            res = max(res, dfs(arr, i + 1, 0, k, n, tempor));
        }
        cout << res << endl;
    }
}
