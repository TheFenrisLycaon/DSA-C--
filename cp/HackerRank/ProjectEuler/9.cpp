#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int N, a, b, c;
        scanf("%d", &N);
        long long pdt = -1;
        for (c = 2; c < N / 2; c++)
        {
            for (b = int((N - c) / 2); b < (N - c); b++)
            {
                if (b > c)
                    break;
                a = N - b - c;
                if ((a > b))
                    continue;
                if (a * a + b * b == c * c)
                {
                    if (pdt < a * b * c)
                        pdt = a * b * c;
                }
            }
        }
        printf("%lld\n", pdt);
    }
    return 0;
}
