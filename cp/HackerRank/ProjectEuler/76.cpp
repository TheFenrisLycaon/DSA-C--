#include <iostream>
#include <vector>
typedef std::vector<unsigned long long> combinations;
int main()
{
    const unsigned int MaxNumber = 1000;
    std::vector<combinations> history;
    unsigned int tests = 1;
    std::cin >> tests;
    while (tests--)
    {
        unsigned int x = 100;
        std::cin >> x;
        for (unsigned int j = history.size(); j <= x; j++)
        {
            combinations ways(MaxNumber, 0);
            ways[0] = 1;
            for (unsigned int i = 1; i < MaxNumber; i++)
            {
                ways[i] = ways[i - 1];
                auto current = i + 1;
                if (j >= current)
                {
                    auto remaining = j - current;
                    ways[i] += history[remaining][i];
                }
                ways[i] %= 1000000007;
            }
            history.push_back(ways);
        }
        auto result = history[x];
        auto combinations = result.back();
        combinations--;
        combinations %= 1000000007;
        std::cout << combinations << std::endl;
    }
    return 0;
}