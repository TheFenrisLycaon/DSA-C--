#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e6 + 2;

int main()
{
    ll t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<int> index;
        int mn = 1e9;
        for (int i = 0; i < n; i++)
        {
            mn = min(mn, (a[0] + b[i]) % n);
        }
        for (int i = 0; i < n; i++)
        {
            if ((a[0] + b[i]) % n == mn)
                index.push_back(i);
        }
        int ans[index.size()][n];
        memset(ans, 1e9, sizeof(ans));
        for (int i = 0; i < index.size(); i++)
        {
            int in = index[i];
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = (a[j] + b[in]) % n;
                in++;
                if (in == n)
                    in = 0;
            }
        }
        vector<int> need;
        for (int i = 0; i < index.size(); i++)
            need.push_back(i);
        for (int i = 0; i < n; i++)
        {
            int m1 = 1e9;
            for (int j = 0; j < need.size(); j++)
                m1 = min(m1, ans[j][i]);
            int k = need.size();
            need.clear();
            for (int j = 0; j < k; j++)
            {
                if (ans[j][i] == m1)
                    need.push_back(j);
            }
            if (need.size() == 1)
                break;
        }
        for (int i = 0; i < n; i++)
            cout << ans[need[0]][i] << " ";
        cout << "\n";
    }
    return 0;
}