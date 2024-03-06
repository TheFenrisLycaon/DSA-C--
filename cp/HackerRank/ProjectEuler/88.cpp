#include <iostream>
#include <vector>

const unsigned int Limit = 200000;
std::vector<unsigned int> minK(Limit, 9999999);

bool valid(unsigned int n, unsigned int k)
{
    if (k >= minK.size())
        return false;
    if (minK[k] > n)
    {
        minK[k] = n;
        return true;
    }
    return false;
}

unsigned int getMinK(unsigned int n, unsigned int product, unsigned int sum,
                     unsigned int depth = 1, unsigned int minFactor = 2)
{
    if (product == 1)
        return valid(n, depth + sum - 1) ? 1 : 0;
    unsigned int result = 0;
    if (depth > 1)
    {
        if (product == sum)
            return valid(n, depth) ? 1 : 0;
        if (valid(n, depth + sum - product))
            result++;
    }
    for (unsigned int i = minFactor; i * i <= product; i++)
        if (product % i == 0)
            result += getMinK(n, product / i, sum - i, depth + 1, i);
    return result;
}

int main()
{
    unsigned int limit;
    std::cin >> limit;
    minK.resize(limit + 1);
    unsigned int n = 4;
    unsigned int sum = 0;
    unsigned int todo = limit - 1;
    while (todo > 0)
    {
        unsigned int found = getMinK(n, n, n);
        if (found > 0)
        {
            todo -= found;
            sum += n;
        }
        n++;
    }
    std::cout << sum << std::endl;
    return 0;
}