#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    const unsigned int MaxLimit = 100 * 1000 * 1000;
    std::vector<unsigned int> primes;
    primes.push_back(2);
    for (unsigned int i = 3; i * i < MaxLimit; i += 2)
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
    std::vector<unsigned int> sums;
    for (auto a : primes)
        for (auto b : primes)
            for (auto c : primes)
            {
                auto a2 = a * a;
                auto b3 = (unsigned long long)b * b * b;
                auto c4 = (unsigned long long)c * c * c * c;
                auto sum = a2 + b3 + c4;
                if (sum > MaxLimit)
                    break;
                sums.push_back(sum);
            }
    std::sort(sums.begin(), sums.end());
    auto last = std::unique(sums.begin(), sums.end());
    unsigned int tests = 1;
    std::cin >> tests;
    while (tests--)
    {
        unsigned int limit = MaxLimit;
        std::cin >> limit;
        auto pos = std::upper_bound(sums.begin(), last, limit);
        auto num = std::distance(sums.begin(), pos);
        std::cout << num << std::endl;
    }
    return 0;
}