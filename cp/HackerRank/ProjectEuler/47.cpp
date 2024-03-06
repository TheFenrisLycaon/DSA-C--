#include <iostream>
#include <vector>
int main()
{
    unsigned int maxNumber = 500000;
    unsigned int consecutive = 4;
    std::cin >> maxNumber >> consecutive;
    maxNumber += consecutive - 1;
    std::vector<unsigned int> primeFactors(maxNumber + 1, 0);
    for (unsigned int i = 2; i <= maxNumber; i++)
        if (primeFactors[i] == 0)
            for (unsigned int j = i; j <= maxNumber; j += i)
                primeFactors[j]++;
    unsigned int currentRun = 0;
    for (unsigned int i = 2; i <= maxNumber; i++)
    {
        if (primeFactors[i] == consecutive)
        {
            currentRun++;
            if (currentRun >= consecutive)
                std::cout << (i - consecutive + 1) << std::endl;
        }
        else
        {
            currentRun = 0;
        }
    }
    return 0;
}
