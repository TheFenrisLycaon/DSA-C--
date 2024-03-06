#include <iostream>
#include <vector>

int main()
{
    unsigned int limit;
    std::cin >> limit;
    std::vector<unsigned int> primes;
    primes.push_back(2);
    for (unsigned int i = 3; i <= limit; i += 2)
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
    std::vector<unsigned int> divsum(limit + 1, 0);
    for (unsigned int i = 2; i <= limit; i++)
    {
        unsigned int sum = 1;
        unsigned int reduce = i;
        for (auto p : primes)
        {
            if (p * p > reduce)
                break;
            unsigned int factor = 1;
            while (reduce % p == 0)
            {
                reduce /= p;
                factor *= p;
                factor++;
            }
            sum *= factor;
        }
        if (reduce > 1 && reduce < i)
            sum *= reduce + 1;
        if (sum > 1)
            sum -= i;
        divsum[i] = sum;
    }
    unsigned int longestChain = 0;
    unsigned int smallestMember = limit;
    for (unsigned int i = 1; i <= limit; i++)
    {
        static std::vector<unsigned int> chain;
        chain.clear();
        chain.push_back(i);
        while (true)
        {
            unsigned int add = divsum[chain.back()];
            chain.push_back(add);
            if (add == i)
                break;
            if (add < i)
                break;
            if (add > limit)
                break;
            bool isLoop = false;
            for (size_t j = 1; j < chain.size() - 1; j++)
                if (add == chain[j])
                {
                    isLoop = true;
                    break;
                }
            if (isLoop)
                break;
        }
        if (chain.back() != i)
            continue;
        if (chain.size() < longestChain)
            continue;
        if (longestChain < chain.size())
        {
            longestChain = chain.size();
            smallestMember = chain.front();
        }
    }
    std::cout << smallestMember << std::endl;
    return 0;
}