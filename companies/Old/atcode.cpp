#include <bits/stdc++.h>

int main() {
    int n, q, i, j, k;

    std::cin >> n >> q;

    std::vector<std::vector<int>> arr(n);

    for (i = 0; i < n; i++)
    {
        int length;
        std::cin >> length;
        arr[i].resize(length);
        for(int j = 0; j < length; j++)
            std::cin >> arr[i][j];
    }

    for (k = 0; k < q; k++)
    {
        std::cin >> i >> j;
        std::cout << arr[i][j]<<std::endl;
    }
    return 0;
}