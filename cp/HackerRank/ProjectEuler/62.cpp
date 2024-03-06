#include <map>
#include <set>
#include <vector>
#include <iostream>
unsigned long long fingerprint(unsigned long long x)
{
    unsigned long long result = 0;
    while (x > 0)
    {
        auto digit = x % 10;
        x /= 10;
        const auto BitsPerDigit = 6;
        result += 1ULL << (BitsPerDigit * digit);
    }
    return result;
}
int main()
{
    unsigned int maxCube = 10000;
    unsigned int numPermutations = 5;
    std::cin >> maxCube >> numPermutations;
    std::map<unsigned long long, std::vector<unsigned int>> matches;
    for (unsigned int i = 1; i < maxCube; i++)
    {
        auto cube = (unsigned long long)i * i * i;
        matches[fingerprint(cube)].push_back(i);
    }
    std::set<unsigned long long> smallest;
    for (auto m : matches)
        if (m.second.size() == numPermutations)
            smallest.insert(m.second.front());
    for (auto s : smallest)
        std::cout << (s * s * s) << std::endl;
    return 0;
}
