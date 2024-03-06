#include <bits/stdc++.h>

struct Citizen
{
    int cobol, val, dou, total;
};

int main(int argc, char const *argv[])
{
    Citizen boomer;
    int n;
    std::vector<Citizen> p;
    std::cin >> n;

    while (n--)
    {
        std::cin >> 
        boomer.cobol >> boomer.val >> boomer.dou;
        boomer.total = boomer.cobol + boomer.val + boomer.dou;
        p.push_back(boomer);
    }

    std::sort(p.begin(), p.end(), [](const auto &one, const auto &two) {
        return (one.val + one.dou) > (two.val + two.dou);
    });

    int stime = 0;
    int mtime = 0;

    for (int i = 0; i < p.size(); ++i)
    {
        boomer = p[i];
        int ftime = stime + boomer.total;
        if (ftime > mtime)
            mtime = ftime;
        stime += boomer.cobol;
    }

    std::cout << mtime << "\n";
    return 0;
}