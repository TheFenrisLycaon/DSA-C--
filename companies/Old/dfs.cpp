#include <bits/stdc++.h>

class Solution
{
public:
    std ::string reverse(std ::string S)
    {
        int n = S.length();
        std ::string res;
        for (int i = 0; i <= n; i++)
            res += S[n - i];
        return res;
    }
};

int main()
{
    Solution o;
    std :: cout<<o.reverse("Anand");
    return 0;
}