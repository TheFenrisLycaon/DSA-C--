#include <vector>
#include <iostream>
#include <cmath>

const double Epsilon = 0.00001;

void eval(const std::vector<double> &numbers, std::vector<bool> &used)
{
    if (numbers.size() == 1)
    {
        auto result = numbers.front() + Epsilon;
        if (fmod(result, 1) > 10 * Epsilon)
            return;
        int index = int(result + Epsilon);
        if (index >= 0 && index < (int)used.size())
            used[index] = true;
        return;
    }
    auto next = numbers;
    for (size_t i = 0; i < numbers.size(); i++)
        for (size_t j = i + 1; j < numbers.size(); j++)
        {
            double a = numbers[i];
            double b = numbers[j];
            next = numbers;
            next.erase(next.begin() + j);
            next.erase(next.begin() + i);
            next.push_back(a + b);
            eval(next, used);
            next.back() = a - b;
            eval(next, used);
            next.back() = b - a;
            eval(next, used);
            next.back() = a * b;
            eval(next, used);
            if (b != 0)
            {
                next.back() = a / b;
                eval(next, used);
            }
            if (a != 0)
            {
                next.back() = b / a;
                eval(next, used);
            }
        }
}

unsigned int getSequenceLength(const std::vector<double> &numbers)
{
    std::vector<bool> used(1000, false);
    eval(numbers, used);
    unsigned int result = 0;
    while (used[result + 1])
        result++;
    return result;
}

int main()
{
    unsigned int numDigits;
    std::cin >> numDigits;
    std::vector<double> numbers(numDigits);
    for (auto &x : numbers)
        std::cin >> x;
    std::cout << getSequenceLength(numbers);
    return 0;
}
