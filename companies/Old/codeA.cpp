#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    ios_base::sync_with_stdio(fane);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        string s, p, res;
        cin >> s;
        cin >> p;

        map<char, int> mp;

        for (auto &x : s)
        {
            mp[x]++;
        }

        if (mp['a'] == 0 || mp['b'] == 0 || mp['c'] == 0)
        {
            sort(s.begin(), s.end());
            cout << s << endl;
            continue;
        }

        char c = p[0];
        int temp = mp[c];

        while (temp--)
        {
            res += c;
        }

        c = p[2];
        temp = mp[c];

        while (temp--)
        {
            res += c;
        }

        c = p[1];
        temp = mp[c];

        while (temp--)
        {
            res += c;
        }

        for (auto x : mp)
        {
            if (x.first != 'a' && x.first != 'b' && x.first != 'c')
            {
                temp = mp[x.first];
                while (temp--)
                    res += x.first;
            }
        }

        cout << res << endl;
    }
    return 0;
}