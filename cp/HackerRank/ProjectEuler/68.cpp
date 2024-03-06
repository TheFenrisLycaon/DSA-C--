#include <iostream>
#include <vector>
#include <string>
#include <set>
std::set<std::string> result;
unsigned int size;
unsigned int tripletSum;
void fillLine(unsigned int pos, std::vector<unsigned int> inner, std::vector<unsigned int> outer, unsigned int used)
{
    if (pos == size - 1)
    {
        outer[size - 1] = tripletSum - (inner[0] + inner[size - 1]);
        unsigned int mask = 1 << outer[size - 1];
        if ((used & mask) != 0)
            return;
        for (auto x : outer)
            if (x < outer[0])
                return;
        std::string id;
        for (unsigned int i = 0; i < size; i++)
            id += std::to_string(outer[i]) + std::to_string(inner[i]) + std::to_string(inner[(i + 1) % size]);
        result.insert(id);
        return;
    }
    for (unsigned int i = 1; i <= 2 * size; i++)
    {
        unsigned int innerMask = 1 << i;
        if ((innerMask & used) != 0)
            continue;
        inner[pos + 1] = i;
        unsigned int nextUsed = used | innerMask;
        outer[pos] = tripletSum - (inner[pos] + i);
        unsigned int outerMask = 1 << outer[pos];
        if ((nextUsed & outerMask) != 0)
            continue;
        nextUsed |= outerMask;
        fillLine(pos + 1, inner, outer, nextUsed);
    }
}
int main()
{
    std::cin >> size >> tripletSum;
    std::vector<unsigned int> inner(size);
    std::vector<unsigned int> outer(size);
    unsigned int allowed = 0;
    for (unsigned int i = 1; i <= 2 * size; i++)
        allowed |= 1 << i;
    allowed = ~allowed;
    for (unsigned int i = 1; i <= 2 * size; i++)
    {
        inner[0] = i;
        fillLine(0, inner, outer, allowed | (1 << i));
    }
#ifdef ORIGINAL
    std::cout << *result.rbegin() << std::endl;
#else
    for (auto r : result)
        std::cout << r << std::endl;
#endif
}