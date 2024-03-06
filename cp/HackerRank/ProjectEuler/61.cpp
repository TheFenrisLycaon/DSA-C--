#include <set>
#include <vector>
#include <iostream>
std::set<unsigned int> results;
const unsigned int Limit = 10000;
std::vector<unsigned int> all(Limit, 0);
unsigned int finalMask = 0;
void add(unsigned int x, unsigned int category)
{
    if (x < 1000 || x >= 10000)
        return;
    auto bit = 1 << category;
    all[x] |= bit & finalMask;
}
void deeper(std::vector<unsigned int> &sequence, unsigned int mask = 0)
{
    unsigned int from = 1000;
    unsigned int to = 10000;
    if (!sequence.empty())
    {
        auto lowerTwoDigits = sequence.back() % 100;
        from = lowerTwoDigits * 100;
        to = from + 100;
    }
    for (auto next = from; next < to; next++)
    {
        auto categories = all[next];
        if (categories == 0)
            continue;
        bool isUnique = true;
        for (auto x : sequence)
            if (x == next)
            {
                isUnique = false;
                break;
            }
        if (!isUnique)
            continue;
        for (auto j = 3; j <= 8; j++)
        {
            auto thisCategory = 1 << j;
            if ((categories & thisCategory) == 0)
                continue;
            if ((mask & thisCategory) != 0)
                continue;
            auto nextMask = mask | thisCategory;
            if (nextMask == finalMask)
            {
                auto first = sequence.front();
                auto lowerTwoDigits = next % 100;
                auto upperTwoDigits = first / 100;
                if (lowerTwoDigits == upperTwoDigits)
                {
                    auto sum = next;
                    for (auto x : sequence)
                        sum += x;
                    results.insert(sum);
                }
            }
            else
            {
                sequence.push_back(next);
                deeper(sequence, nextMask);
                sequence.pop_back();
            }
        }
    }
}
int main()
{
    unsigned int numSets;
    std::cin >> numSets;
    for (unsigned int i = 0; i < numSets; i++)
    {
        unsigned int x;
        std::cin >> x;
        finalMask |= 1 << x;
    }
    unsigned int n = 1;
    while (true)
    {
        auto triangle = n * (n + 1) / 2;
        if (triangle >= 10000)
            break;
        add(triangle, 3);
        auto square = n * n;
        add(square, 4);
        auto pentagon = n * (3 * n - 1) / 2;
        add(pentagon, 5);
        auto hexagon = n * (2 * n - 1);
        add(hexagon, 6);
        auto heptagon = n * (5 * n - 3) / 2;
        add(heptagon, 7);
        auto octagon = n * (3 * n - 2);
        add(octagon, 8);
        n++;
    }
    std::vector<unsigned int> sequence;
    deeper(sequence);
    for (auto x : results)
        std::cout << x << std::endl;
    return 0;
}
 