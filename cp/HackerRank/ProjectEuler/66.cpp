#include <cmath>
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
        if (factor == 0)
            return 0;
        if (factor == 1)
            return *this;
        if (factor == MaxDigit)
        {
            auto result = *this;
            result.insert(result.begin(), 0);
            return result;
        }
        if (factor > MaxDigit)
            return *this * BigNum(factor);
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
    BigNum operator*(const BigNum &other) const
    {
        BigNum result = 0;
        for (int i = (int)other.size() - 1; i >= 0; i--)
            result = result * MaxDigit + (*this * other[i]);
        return result;
    }
    bool operator<(const BigNum &other) const
    {
        if (size() < other.size())
            return true;
        if (size() > other.size())
            return false;
        for (int i = (int)size() - 1; i >= 0; i--)
        {
            if (operator[](i) < other[i])
                return true;
            if (operator[](i) > other[i])
                return false;
        }
        return false;
    }
};
int main()
{
    unsigned int limit = 1000;
    std::cin >> limit;
    unsigned int bestD = 2;
    BigNum bestX = 3;
    for (unsigned int d = 3; d <= limit; d++)
    {
        unsigned int root = sqrt(d);
        if (root * root == d)
            continue;
        unsigned int a = root;
        unsigned int numerator = 0;
        unsigned int denominator = 1;
        BigNum x[3] = {0, 1, root};
        BigNum y[3] = {0, 0, 1};
        while (true)
        {
            numerator = denominator * a - numerator;
            denominator = (d - numerator * numerator) / denominator;
            a = (root + numerator) / denominator;
            x[0] = std::move(x[1]);
            x[1] = std::move(x[2]);
            x[2] = x[1] * a + x[0];
            y[0] = std::move(y[1]);
            y[1] = std::move(y[2]);
            y[2] = y[1] * a + y[0];
            auto leftSide = x[2] * x[2];
            auto rightSide = y[2] * y[2] * d + 1;
            if (leftSide == rightSide)
                break;
        }
        if (bestX < x[2])
        {
            bestX = x[2];
            bestD = d;
        }
    }
    std::cout << bestD << std::endl;
    return 0;
}