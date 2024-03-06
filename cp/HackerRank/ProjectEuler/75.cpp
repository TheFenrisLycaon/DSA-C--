#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
template <typename T>
T gcd(T a, T b)
{
    while (a != 0)
    {
        T c = a;
        a = b % a;
        b = c;
    }
    return b;
}
int main()
{
    const unsigned int MaxLength = 5 * 1000 * 1000;
    std::vector<unsigned int> combinations(MaxLength, 0);
    for (unsigned int m = 2; m < sqrt(MaxLength); m++)
        for (unsigned int n = 1; n < m; n++)
        {
            if ((m + n) % 2 != 1)
                continue;
            if (gcd(m, n) != 1)
                continue;
            auto a = m * m - n * n;
            auto b = 2 * m * n;
            auto c = m * m + n * n;
            auto sum = a + b + c;
            unsigned int k = 1;
            while (k * sum <= MaxLength)
            {
                combinations[k * sum]++;
                k++;
            }
        }
    std::vector<unsigned int> once;
    for (size_t i = 0; i < combinations.size(); i++)
        if (combinations[i] == 1)
            once.push_back(i);
    unsigned int tests = 1;
    std::cin >> tests;
    while (tests--)
    {
        unsigned int limit = 1500000;
        std::cin >> limit;
        auto pos = std::upper_bound(once.begin(), once.end(), limit);
        auto result = std::distance(once.begin(), pos);
        std::cout << result << std::endl;
    }
}