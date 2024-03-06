#include <iostream>
unsigned long long fingerprint(unsigned int x)
{
    unsigned long long result = 0;
    while (x > 0)
    {
        auto digit = x % 10;
        x /= 10;
        unsigned long long pos = 1;
        for (unsigned int i = 1; i <= digit; i++)
            pos *= 10;
        result += pos;
    }
    return result;
}
int main()
{
    unsigned int maxNumber = 1000000;
    unsigned int maxMultiple = 6;
    ;
    std::cin >> maxNumber >> maxMultiple;
    for (unsigned int i = 1; i <= maxNumber; i++)
    {
        auto id = fingerprint(i);
        bool found = true;
        for (unsigned int multiple = 2; multiple <= maxMultiple; multiple++)
            if (id != fingerprint(i * multiple))
            {
                found = false;
                break;
            }
        if (found)
        {
#ifdef ORIGINAL
            std::cout << i << std::endl;
            return 0;
#endif
            for (unsigned int multiple = 1; multiple <= maxMultiple; multiple++)
                std::cout << (i * multiple) << " ";
            std::cout << std::endl;
        }
    }
    return 0;
}
