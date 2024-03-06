#include <iostream>
#include <vector>
unsigned int maxD = 12000;
unsigned int recursion(unsigned int fromD, unsigned int toD)
{
    auto medD = fromD + toD;
    if (medD > maxD)
        return 0;
    return 1 + recursion(fromD, medD) + recursion(medD, toD);
}
unsigned int iteration(unsigned int fromD, unsigned int toD)
{
    auto d = fromD + toD;
    while (d + fromD <= maxD)
        d += fromD;
    auto prevD = fromD;
    unsigned int count = 0;
    while (d != toD)
    {
        auto nextD = maxD - (maxD + prevD) % d;
        prevD = d;
        d = nextD;
        count++;
    }
    return count;
}
unsigned int rank(unsigned int n, unsigned int d)
{
    std::vector<unsigned int> data(maxD + 1);
    for (unsigned int i = 0; i < data.size(); i++)
        data[i] = i * n / d;
    for (unsigned int i = 1; i < data.size(); i++)
        for (unsigned int j = 2 * i; j < data.size(); j += i)
            data[j] -= data[i];
    unsigned int sum = 0;
    for (auto x : data)
        sum += x;
    return sum;
}
int main()
{
    unsigned int toD = 2;
#ifndef ORIGINAL
    std::cin >> toD >> maxD;
#endif
    auto fromD = toD + 1;
    auto result = rank(1, toD) - rank(1, fromD) - 1;
    std::cout << result << std::endl;
    return 0;
}