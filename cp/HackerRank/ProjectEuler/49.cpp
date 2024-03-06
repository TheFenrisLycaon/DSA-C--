#include <set>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
unsigned long long fingerprint(unsigned int x)
{
    unsigned long long result = 0;
    while (x > 0)
    {
        auto digit = x % 10;
        x /= 10;
        unsigned long long pos = 1;
        for (unsigned int i = 1; i <= digit; i++)
            pos *= 10;
        result += pos;
    }
    return result;
}
int main()
{
    unsigned int limit = 10000;
    unsigned int sequenceLength = 4;
    std::cin >> limit >> sequenceLength;
    std::set<unsigned int> primes;
    primes.insert(2);
    for (unsigned int i = 3; i < 1000000; i += 2)
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
            primes.insert(i);
    }
    std::map<unsigned long long, unsigned int> fingerprints;
    for (auto p : primes)
        fingerprints[fingerprint(p)]++;
    std::map<unsigned int, std::set<std::string>> result;
    for (auto p : primes)
    {
        if (p < 1000)
            continue;
        if (p >= limit)
            break;
        if (fingerprints[fingerprint(p)] < 3)
            continue;
        std::string digits = std::to_string(p);
        std::sort(digits.begin(), digits.end());
        std::set<unsigned int> candidates;
        do
        {
            if (digits[0] == '0')
                continue;
            unsigned int permuted = std::stoi(digits);
            if (primes.count(permuted) == 0)
                continue;
            if (permuted < p)
                break;
            candidates.insert(permuted);
        } while (std::next_permutation(digits.begin(), digits.end()));
        if (candidates.size() < sequenceLength)
            continue;
        std::map<unsigned int, std::set<unsigned int>> differences;
        for (auto bigger : candidates)
            for (auto smaller : candidates)
            {
                if (smaller >= bigger)
                    break;
                differences[bigger - smaller].insert(bigger);
                differences[bigger - smaller].insert(smaller);
            }
        for (auto d : differences)
        {
            if (d.second.size() < sequenceLength)
                continue;
            auto diff = d.first;
            auto all = d.second;
            for (auto start : all)
            {
                if (start >= limit)
                    continue;
                unsigned int followers = 0;
                unsigned int next = start + diff;
                while (all.count(next) != 0)
                {
                    followers++;
                    next += diff;
                }
                if (followers >= sequenceLength - 1)
                {
                    auto next = start + diff;
                    std::string s = std::to_string(start);
                    for (unsigned int printMe = 1; printMe < sequenceLength; printMe++)
                    {
                        s += std::to_string(next);
                        next += diff;
                    }
                    result[s.size()].insert(s);
                }
            }
        }
    }
    for (auto length : result)
        for (auto x : length.second)
#ifdef ORIGINAL
            if (x != "148748178147") 
#endif
                std::cout << x << std::endl;
    return 0;
}
