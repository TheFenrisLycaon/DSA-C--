#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

unsigned long long fingerprint(unsigned long long x)
{
    unsigned long long result = 0;
    while (x > 0)
    {
        auto digit = x % 10;
        x /= 10;
        result += 1LL << (4 * digit);
    }
    return result;
}

int main()
{
    unsigned int digits;
    std::cin >> digits;
    unsigned long long minNumber = 1;
    for (unsigned int i = 1; i < digits; i++)
        minNumber *= 10;
    unsigned long long maxNumber = minNumber * 10 - 1;
    unsigned long long base = sqrt(minNumber);
    if (base * base < minNumber)
        base++;
    std::map<unsigned long long, std::vector<unsigned long long>> permutations;
    while (base * base <= maxNumber)
    {
        auto square = base * base;
        permutations[fingerprint(square)].push_back(square);
        base++;
    }
    size_t bestCount = 0;
    unsigned long long highestSquare = 0;
    for (auto p : permutations)
    {
        auto size = p.second.size();
        auto high = p.second.back();
        if (bestCount == size && highestSquare < high)
            highestSquare = high;
        if (bestCount < size)
        {
            bestCount = size;
            highestSquare = high;
        }
    }
    std::cout << highestSquare << std::endl;
}
