#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        vector<int> ans2;
        int a[n], max = a[0], min = a[0];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            ans.emplace_back(a[i]);
            ans2.emplace_back(a[i]);
        }
        vector<vector<int>> final;
        for (int i = 0; i < n; i++)
        {
            final.emplace_back(a[i]);
            max = a[i];
        }
        cout << max << endl;
    }
    return 0;
}
