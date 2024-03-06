#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> arr;
int n;
int cost(int x)
{
    if ((x == n - 1) || x == 0)
        return 0;
    if ((arr[x] > arr[x - 1]) && (arr[x] > arr[x + 1]))
        return 1;
    if (arr[x] < arr[x - 1] && arr[x] < arr[x + 1])
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr.clear();
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        ll ans = 0;
        vector<int> work(n, 0);
        for (int i = 1; i < n - 1; i++)
            if (cost(i))
            {
                ans++;
                work[i] = 1;
            }
        ll res = ans;
        ll val = ans;
        for (int i = 1; i < n - 1; i++)
        {
            ll prev = work[i] + work[i - 1] + work[i + 1];
            int x = arr[i];
            arr[i] = arr[i + 1];
            res = min(res, ans + cost(i - 1) + cost(i) + cost(i + 1) - prev);
            arr[i] = arr[i - 1];
            res = min(res, ans + cost(i - 1) + cost(i) + cost(i + 1) - prev);
            arr[i] = x;
            val = min(res, val);
        }
        cout << res << endl;
    }
    return 0;
}