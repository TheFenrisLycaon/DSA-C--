#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long perm(int n)
    {
        long long ans = 1;
        if (n == 0 || n == 1)
            return 1ll;
        else
        {
            for (int i = 1; i <= n; i++)
                ans *= (i * 1ll);
        }
        return ans;
    }
    long long findRank(string str)
    {
        int len = str.length();
        long long ans = 0;
        for (int i = 0; i < len; i++)
        {
            int less = 0;
            for (int j = i + 1; j < len; j++)
            {
                if (str[j] < str[i])
                    less++;
            }
            ans += less * perm(len - 1 - i);
        }
        ans += 1;
        return ans;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout << ans << endl;
    }
}