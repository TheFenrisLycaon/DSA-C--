#include <iostream>
#include <vector>
struct BigNum : public std::vector<unsigned int>
{
    static const unsigned int MaxDigit = 1000000000;
    BigNum(unsigned long long x = 0)
    {
        do
        {
            push_back(x % MaxDigit);
            x /= MaxDigit;
        } while (x > 0);
    }
    BigNum operator+(const BigNum &other) const
    {
        auto result = *this;
        if (result.size() < other.size())
            result.resize(other.size(), 0);
        unsigned int carry = 0;
        for (size_t i = 0; i < result.size(); i++)
        {
            carry += result[i];
            if (i < other.size())
                carry += other[i];
            else if (carry == 0)
                return result;
            if (carry < MaxDigit)
            {
                result[i] = carry;
                carry = 0;
            }
            else
            {
                result[i] = carry - MaxDigit;
                carry = 1;
            }
        }
        if (carry > 0)
            result.push_back(carry);
        return result;
    }
    BigNum operator*(unsigned int factor) const
    {
        unsigned long long carry = 0;
        auto result = *this;
        for (auto &i : result)
        {
            carry += i * (unsigned long long)factor;
            i = carry % MaxDigit;
            carry /= MaxDigit;
        }
        while (carry > 0)
        {
            result.push_back(carry % MaxDigit);
            carry /= MaxDigit;
        }
        return result;
    }
};
int main()
{
    unsigned int lastIndex;
    std::cin >> lastIndex;
    BigNum numerators[3] = {0,
                            1,
                            2};
    for (unsigned int index = 2; index <= lastIndex; index++)
    {
        unsigned int fractionNumber = 1;
        if (index % 3 == 0)
            fractionNumber = (index / 3) * 2;
        numerators[0] = std::move(numerators[1]);
        numerators[1] = std::move(numerators[2]);
        if (fractionNumber == 1)
            numerators[2] = numerators[0] + numerators[1];
        else
            numerators[2] = numerators[0] + numerators[1] * fractionNumber;
    }
    unsigned int sum = 0;
    for (auto x : numerators[2])
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
    std::cout << sum << std::endl;
    return 0;
}