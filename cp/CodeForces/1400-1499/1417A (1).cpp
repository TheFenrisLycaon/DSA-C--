// Question: https://codeforces.com/problemset/problem/1417/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        int mn = *min_element(a.begin(), a.end());
        int mini = min_element(a.begin(), a.end()) - a.begin();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != mini)
            {
                count += (k - a[i]) / mn;
            }
        }
        cout << count << endl;
    }
    return 0;
}
