#include <iostream>
unsigned int check(unsigned int digits)
{
    unsigned int count = 0;
#ifdef ORIGINAL
    typedef double Number;
#else
    typedef unsigned long long Number;
#endif
    Number to = 1;
    for (unsigned int i = 1; i <= digits; i++)
        to *= 10;
    Number from = to / 10;
    to--;
    for (unsigned int base = 1; base <= 9; base++)
    {
        Number power = base;
        for (unsigned int i = 1; i < digits && power <= to; i++)
            power *= base;
        if (power >= from && power <= to)
        {
            count++;
#ifndef ORIGINAL
            std::cout << std::fixed << power << std::endl;
#endif
        }
    }
    return count;
}
int main()
{
#ifdef ORIGINAL
    unsigned int count = 0;
    for (unsigned int digits = 1; digits <= 21; digits++)
        count += check(digits);
    std::cout << count << std::endl;
#else
    unsigned int digits = 9;
    std::cin >> digits;
    check(digits);
#endif
    return 0;
}