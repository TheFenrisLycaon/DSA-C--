#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    char ms[128] = {0}, mt[128] = {0};
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (ms[s[i]] != mt[t[i]])
            return false;

        ms[s[i]] = i + 1;
        mt[t[i]] = i + 1;
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << isIsomorphic(s, t) << endl;
}