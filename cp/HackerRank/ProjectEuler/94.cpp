#include <cmath>
#include <vector>
#include <iostream>

std::vector<unsigned long long> solutions;

bool isValidTriangle(unsigned long long oneSide, unsigned long long twoSides)
{
    unsigned long long check = 4 * twoSides * twoSides - oneSide * oneSide;
    unsigned long long root = sqrt(check);
    return root * root == check;
}

unsigned long long findMore(unsigned long long perimeter, unsigned long long limit)
{
    while (perimeter <= limit + 3)
    {
        auto twoSides = perimeter / 3;
        auto oneSide = twoSides - 1;
        if (isValidTriangle(oneSide, twoSides))
            solutions.push_back(perimeter - 1);
        oneSide = twoSides + 1;
        if (isValidTriangle(oneSide, twoSides))
            solutions.push_back(perimeter + 1);
        perimeter += 3;
    }
    return perimeter;
}

unsigned long long sequence(unsigned long long limit)
{
    unsigned long long plusOne[] = {1, 5};
    unsigned long long minusOne[] = {1, 17};
    solutions.clear();
    solutions.push_back(3 * plusOne[1] + 1);
    solutions.push_back(3 * minusOne[1] - 1);
    while (solutions.back() <= limit + 3)
    {
        unsigned long long nextPlusOne = 14 * plusOne[1] - plusOne[0] - 4;
        unsigned long long nextMinusOne = 14 * minusOne[1] - minusOne[0] + 4;
        plusOne[0] = plusOne[1];
        plusOne[1] = nextPlusOne;
        minusOne[0] = minusOne[1];
        minusOne[1] = nextMinusOne;
        solutions.push_back(3 * nextPlusOne + 1);
        solutions.push_back(3 * nextMinusOne - 1);
    }
    return solutions.back();
}

int main()
{
    solutions.push_back(16);
    unsigned long long perimeter = 18;
    unsigned int tests = 1;
    std::cin >> tests;
    while (tests--)
    {
        unsigned long long limit = 1000000000;
        std::cin >> limit;
        while (perimeter <= limit + 3)
            perimeter = sequence(limit);
        unsigned long long sum = 0;
        for (auto x : solutions)
            if (x <= limit)
                sum += x;
        std::cout << sum << std::endl;
    }
    return 0;
}