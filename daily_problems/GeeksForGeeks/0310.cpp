#include <bits/stdc++.h>

class Solution
{
public:
    std ::string sevenSegments(std ::string S, int N)
    {
        int arr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
        int ans[N];
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[S[i] - '0'];
        }
        for (int i = 0; i < N; i++)
        {
            ans[i] = 2;
            sum -= 2;
        }
        int i = 0;
        while (sum >= 4 and i < N)
        {
            ans[i] = 6;
            sum += 2;
            sum -= 6;
            i++;
        }
        ans[N - 1] += sum;
        std ::string res = "";
        for (int i = 0; i < N; i++)
        {
            if (ans[i] == 6)
                res += '0';
            else if (ans[i] == 2)
                res += '1';
            else if (ans[i] == 3)
                res += '7';
            else if (ans[i] == 4)
                res += '4';
            else
                res += '2';
        }
        return res;
    }
};

int main()
{
    int t;
    std ::cin >> t;
    while (t--)
    {
        int N;
        std ::cin >> N;
        std ::string S;
        std ::cin >> S;
        Solution ob;
        std ::cout << ob.sevenSegments(S, N) << std::endl;
    }
    return 0;
}
