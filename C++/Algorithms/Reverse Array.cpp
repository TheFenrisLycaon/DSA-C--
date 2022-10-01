/// time complexity = theta(n), aux space = theta(1)

#include <bits/stdc++.h>

int main()
{
    int arr[] = {10, 20, 4, 22};
    int n = 4, low = 0, high = n - 1;

    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }

    for (int i = 0; i < n; i++)
        std :: cout << arr[i] << " ";
    return 0;
}
