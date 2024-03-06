#include <iostream>

long long gcd(long long int a, long long int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

long long findlcm(long long int m, long long int n)
{
    long long int ans = m;

    for (long long int i = m; i <= n; i++)
        ans = (i * ans) / gcd(i, ans);

    return ans;
}

int main()
{
    long long int a,b;
    std :: cin >> a >> b;
    std ::cout << findlcm(a,b) << std::endl;
    return 0;
}
