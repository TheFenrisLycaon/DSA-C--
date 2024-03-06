#include <bits/stdc++.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int c, f;
    std::cin >> c >> f;
    int gph[c][c];
    int i, j, k, x, y, p;

    for (i = 0; i < c; ++i)
        for (j = 0; j < c; ++j)
            gph[i][j] = 100000000;

    for (i = 0; i < c; ++i)
        gph[i][i] = 0;

    for (i = 0; i < f; ++i)
    {
        std::cin >> x >> y >> p;
        gph[x - 1][y - 1] = p;
        gph[y - 1][x - 1] = p;
    }

    int d[c][c];
    for (i = 0; i < c; ++i)
        for (j = 0; j < c; ++j)
            d[i][j] = gph[i][j];

    for (k = 0; k < c; ++k)
        for (i = 0; i < c; ++i)
            for (j = 0; j < c; ++j)
                if (d[i][j] > d[i][k] + d[j][k])
                    d[i][j] = d[i][k] + d[j][k];

    int max_min = 0;
    for (i = 0; i < c; ++i)
        for (j = 0; j < c; ++j)
            max_min = std::max(max_min, d[i][j]);

    std::cout << max_min << "\n";
    return 0;
}