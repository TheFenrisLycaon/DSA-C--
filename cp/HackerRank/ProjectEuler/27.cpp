#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

bool is_prime(int p)
{
    if (p < 2)
        return false;
    for (int i = 2; i * i <= p; i++)
    {
        if ((p % i) == 0)
            return false;
    }
    return true;
}
int main()
{
    int N, max_count = 0, besta, bestb;
    scanf("%d", &N);
    for (int b = 2; b <= N; b++)
    {
        if (!(is_prime(b)))
            continue;
        for (int a = -b; a <= N; a++)
        {
            int count = 0;
            for (int n = 0;; ++n)
            {
                int p = (n * n) + (a * n) + b;
                if (is_prime(p))
                    count++;
                else
                    break;
            }
            if (count > max_count)
            {
                max_count = count;
                besta = a;
                bestb = b;
            }
        }
    }
    printf("%d %d\n", besta, bestb);
}