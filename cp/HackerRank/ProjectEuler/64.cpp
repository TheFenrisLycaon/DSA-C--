#include <cmath>
#include <iostream>
unsigned int getPeriodLength(unsigned int x)
{
    unsigned int root = sqrt(x);
    if (root * root == x)
        return 0;
    unsigned int a = root;
    unsigned int numerator = 0;
    unsigned int denominator = 1;
    unsigned int period = 0;
    while (a != 2 * root)
    {
        numerator = denominator * a - numerator;
        denominator = (x - numerator * numerator) / denominator;
        a = (root + numerator) / denominator;
        period++;
    }
    return period;
}
int main()
{
    unsigned int last;
    std::cin >> last;
    unsigned int numOdd = 0;
    for (unsigned int i = 2; i <= last; i++)
    {
        unsigned int period = getPeriodLength(i);
        if (period % 2 == 1)
            numOdd++;
    }
    std::cout << numOdd << std::endl;
    return 0;
}