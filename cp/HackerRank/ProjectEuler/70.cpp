#include <iostream>
#include <vector>
std::vector<unsigned int> primes;
unsigned int phi(unsigned int x, double MinQ)
{
    auto res = x;
    auto red = x;
    for (auto p : primes)
    {
        if (p * p > red)
            break;
        if (red % p != 0)
            continue;
        do
        {
            red /= p;
        } while (red % p == 0);
        res -= res / p;
        if (res * MinQ < x)
            return res;
    }
    if (res == x)
        return x - 1;
    if (red > 1)
        return res - res / red;
    else
        return res;
}
unsigned long long fingerprint(unsigned int x)
{
    unsigned long long res = 0;
    while (x > 0)
    {
        auto digit = x % 10;
        x /= 10;
        unsigned long long shift = 1;
        for (unsigned int i = 0; i < digit; i++)
            shift *= 10;
        res += shift;
    }
    return res;
}
int main()
{
    unsigned int last;
    std::cin >> last;
    primes.push_back(2);
    for (unsigned int i = 3; i * i < last; i += 2)
    {
        bool isPrime = true;
        for (auto p : primes)
        {
            if (p * p > i)
                break;
            if (i % p == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primes.push_back(i);
    }
    unsigned int bestNumber = 2;
    double MinQ = 999999;
    for (unsigned int n = 3; n < last; n++)
    {
        auto phi_n = phi(n, MinQ);
        double quotient = n / double(phi_n);
        if (MinQ <= quotient)
            continue;
        if (fingerprint(phi_n) == fingerprint(n))
        {
            MinQ = quotient;
            bestNumber = n;
        }
    }
    std::cout << bestNumber << std::endl;
    return 0;
}