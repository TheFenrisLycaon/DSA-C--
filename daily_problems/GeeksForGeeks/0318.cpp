#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(int A[], int N, int K)
    {
        sort(A, A + N);
        long long sum = 0;
        long long pre[N] = {};
        pre[0] = A[0];
        for (int i = 1; i < N; i++)
        {
            pre[i] = pre[i - 1] + A[i];
        }
        sum = pre[N - 1];
        int ans = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            int mn = A[i];
            int temp = pre[i] - A[i];
            int ind = lower_bound(A + i + 1, A + N, mn + K + 1) - A;
            if (ind < N)
            {
                temp += (sum - pre[ind] + A[ind]) - (N - ind) * (mn + K);
            }
            ans = min(ans, temp);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.minSteps(A, N, K) << endl;
    }
    return 0;
}