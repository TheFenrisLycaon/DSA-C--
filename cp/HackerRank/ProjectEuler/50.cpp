#include <iostream>
#include <vector>
unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long modulo)
{
    if (a <= 0xFFFFFFF && b <= 0xFFFFFFF)
        return (a * b) % modulo;
    unsigned long long result = 0;
    unsigned long long factor = a % modulo;
    while (b > 0)
    {
        if (b & 1)
        {
            result += factor;
            if (result >= modulo)
                result %= modulo;
        }
        factor <<= 1;
        if (factor >= modulo)
            factor %= modulo;
        b >>= 1;
    }
    return result;
}
unsigned long long powmod(unsigned long long base, unsigned long long exponent, unsigned long long modulo)
{
    unsigned long long result = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = mulmod(result, base, modulo);
        base = mulmod(base, base, modulo);
        exponent >>= 1;
    }
    return result;
}
bool isPrime(unsigned long long p)
{
    const unsigned int bitmaskPrimes2to31 = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) |
                                            (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19) |
                                            (1 << 23) | (1 << 29);
    if (p < 31)
        return (bitmaskPrimes2to31 & (1 << p)) != 0;
    if (p % 2 == 0 || p % 3 == 0 || p % 5 == 0 || p % 7 == 0 ||
        p % 11 == 0 || p % 13 == 0 || p % 17 == 0)
        return false;
    if (p < 17 * 19)
        return true;
    const unsigned int STOP = 0;
    const unsigned int TestAgainst1[] = {377687, STOP};
    const unsigned int TestAgainst2[] = {31, 73, STOP};
    const unsigned int TestAgainst3[] = {2, 7, 61, STOP};
    const unsigned int TestAgainst4[] = {2, 13, 23, 1662803, STOP};
    const unsigned int TestAgainst7[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022, STOP};
    const unsigned int *testAgainst = TestAgainst7;
    if (p < 5329)
        testAgainst = TestAgainst1;
    else if (p < 9080191)
        testAgainst = TestAgainst2;
    else if (p < 4759123141ULL)
        testAgainst = TestAgainst3;
    else if (p < 1122004669633ULL)
        testAgainst = TestAgainst4;
    auto d = p - 1;
    d >>= 1;
    unsigned int shift = 0;
    while ((d & 1) == 0)
    {
        shift++;
        d >>= 1;
    }
    do
    {
        auto x = powmod(*testAgainst++, d, p);
        if (x == 1 || x == p - 1)
            continue;
        bool maybePrime = false;
        for (unsigned int r = 0; r < shift; r++)
        {
            x = powmod(x, 2, p);
            if (x == 1)
                return false;
            if (x == p - 1)
            {
                maybePrime = true;
                break;
            }
        }
        if (!maybePrime)
            return false;
    } while (*testAgainst != STOP);
    return true;
}
std::vector<unsigned int> primes;
std::vector<unsigned long long> primeSum;
void morePrimes(unsigned int num)
{
    if (primes.empty())
    {
        primes.reserve(400000);
        primeSum.reserve(400000);
        primes.push_back(2);
        primes.push_back(3);
        primeSum.push_back(2);
    }
    for (auto i = primes.back() + 2; primes.size() <= num; i += 2)
    {
        bool isPrime = true;
        for (auto x : primes)
        {
            if (x * x > i)
                break;
            if (i % x == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primes.push_back(i);
    }
    for (auto i = primeSum.size(); i < primes.size(); i++)
        primeSum.push_back(primeSum.back() + primes[i]);
}
int main()
{
    const unsigned int PrimesPerBatch = 10000;
    morePrimes(PrimesPerBatch);
    unsigned int tests;
    std::cin >> tests;
    while (tests--)
    {
        unsigned long long last = 1000000;
        std::cin >> last;
        unsigned long long best = 2;
        unsigned int maxLength = 0;
        unsigned int start = 0;
        while (primes[start] <= 131 && primes[start] <= last)
        {
            unsigned long long subtract = 0;
            if (start > 0)
                subtract = primeSum[start - 1];
            unsigned int pos = start + maxLength;
            while (primeSum[pos] - subtract <= last)
            {
                pos++;
                if (pos + 100 >= primes.size())
                    morePrimes(primes.size() + PrimesPerBatch);
            }
            pos--;
            while (pos - start > maxLength)
            {
                unsigned long long sum = primeSum[pos] - subtract;
                if (isPrime(sum))
                {
                    maxLength = pos - start;
                    best = sum;
                    break;
                }
                pos--;
            }
            start++;
        }
        if (best >= 2)
            maxLength++;
        std::cout << best << " " << maxLength << std::endl;
    }
    return 0;
}
