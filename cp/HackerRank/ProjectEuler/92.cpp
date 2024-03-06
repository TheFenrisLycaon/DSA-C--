#include <iostream>
bool becomes89(unsigned int x)
{
    do
    {
        unsigned int squareDigitSum = 0;
        auto reduce = x;
        while (reduce > 0)
        {
            auto digit = reduce % 10;
            reduce /= 10;
            squareDigitSum += digit * digit;
        }
        if (squareDigitSum == 89)
            return true;
        if (squareDigitSum == 1)
            return false;
        x = squareDigitSum;
    } while (true);
}
int main()
{
    unsigned int digits = 7;
    std::cin >> digits;
    const unsigned int Modulo = 1000000007;
    unsigned int sums[200 * 9 * 9 + 1] = {0};
    for (unsigned int first = 0; first <= 9; first++)
        sums[first * first]++;
    for (unsigned int length = 2; length <= digits; length++)
        for (unsigned int sum = length * 9 * 9; sum > 0; sum--)
            for (unsigned int high = 1; high <= 9; high++)
            {
                auto square = high * high;
                if (square > sum)
                    break;
                sums[sum] += sums[sum - square];
                sums[sum] %= Modulo;
            }
    unsigned int count89 = 0;
    for (unsigned int i = 1; i <= digits * 9 * 9; i++)
        if (becomes89(i))
        {
            count89 += sums[i];
            count89 %= Modulo;
        }
    std::cout << count89 << std::endl;
    return 0;
}