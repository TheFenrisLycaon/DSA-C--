#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()

int N, K;
vi A, FW, BW;

int Forward(int n)
{
    if (n < K)
        return -INF;
    if (n == K)
        return FW[n] = 0;
    if (FW[n] != -INF)
        return FW[n];
    FW[n] = A[n] + max(Forward(n - 1), Forward(n - 2));
    return FW[n];
}

int Backward(int n)
{
    if (n < 0)
        return -INF;
    if (n == 0)
        return BW[n] = A[0];
    if (BW[n] != -INF)
        return BW[n];
    BW[n] = A[n] + max(Backward(n - 1), Backward(n - 2));
    return BW[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    K--;
    A.resize(N);
    FW.resize(N, -INF), BW.resize(N, -INF);
    for (auto &i : A)
        cin >> i;
    Forward(N - 1);
    Backward(N - 1);
    int ans = -INF;
    for (int n = K; n < N; n++)
    {
        int maxi = FW[n] + BW[n] - A[n];
        ans = max(ans, maxi);
    }
    cout << ans << endl;
    return 0;
}