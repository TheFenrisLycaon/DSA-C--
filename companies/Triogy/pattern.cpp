#include <bits/stdc++.h>

int main()
{
    int n, space, i, j, left = 1, right;
    std::cin >> n;
    right = n * n + 1;

    for (i = n; i > 0; i--)
    {
        for (space = n; space > i; space--)
            std::cout << " ";

        for (j = 1; j <= i; j++)
        {
            std::cout << left << "*";
            left++;
        }

        for (j=1; j<= i; j++)
        {
            std :: cout << right;
            if (j<i)
                printf("*");
            right ++;
        }
        std :: cout << '\n';
    }
    return 0;
}