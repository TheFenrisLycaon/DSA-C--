#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
std::string n2s(unsigned int x, unsigned int digits)
{
    std::string res;
    while (digits-- > 0)
    {
        auto digit = x % 10;
        res += char(digit + '0');
        x /= 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
unsigned int str2num(const std::string &str)
{
    unsigned int res = 0;
    for (auto s : str)
    {
        res *= 10;
        res += s - '0';
    }
    return res;
}
unsigned int merge(const std::string &strFill, const std::string &mask)
{
    auto iteFill = strFill.begin();
    unsigned int res = 0;
    for (auto m : mask)
    {
        res *= 10;
        if (m == '.')
            res += *iteFill++ - '0';
        else
            res += m - '0';
    }
    return res;
}
int main()
{
    unsigned int digits;
    unsigned int cancel;
    std::cin >> digits >> cancel;
    auto keep = digits - cancel;
    const unsigned int Tens[] = {1, 10, 100, 1000, 10000};
    unsigned int sumN = 0;
    unsigned int sumD = 0;
    std::unordered_set<unsigned int> used;
    for (unsigned int d = 1; d < Tens[keep]; d++)
        for (unsigned int n = 1; n < d; n++)
        {
            auto strN = n2s(n, keep);
            auto strD = n2s(d, keep);
            for (auto insert = Tens[cancel - 1]; insert < Tens[cancel]; insert++)
            {
                auto strInsert = n2s(insert, cancel);
                bool isAscending = true;
                for (size_t i = 1; i < strInsert.size(); i++)
                    if (strInsert[i - 1] > strInsert[i])
                    {
                        isAscending = false;
                        break;
                    }
                if (!isAscending)
                    continue;
                strInsert.insert(0, keep, '.');
                auto strInsertN = strInsert;
                do
                {
                    auto newN = merge(strN, strInsertN);
                    if (newN < Tens[digits - 1])
                        continue;
                    auto strInsertD = strInsert;
                    do
                    {
                        auto newD = merge(strD, strInsertD);
                        if (newN * d == newD * n)
                        {
                            auto id = newN * 10000 + newD;
                            if (used.count(id) == 0)
                            {
                                sumN += newN;
                                sumD += newD;
                                used.insert(id);
                            }
                        }
                    } while (std::next_permutation(strInsertD.begin(), strInsertD.end()));
                } while (std::next_permutation(strInsertN.begin(), strInsertN.end()));
            }
        }
    std::cout << sumN << " " << sumD << std::endl;
    return 0;
}
