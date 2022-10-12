// CPP program to find the most frequent element in an array.
#include <bits/stdc++.h>
using namespace std;

int mostFrequent(int *arr, int n)
{
    // code is here
    int maxcount = 0;
    int element_having_max_freq;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxcount)
        {
            maxcount = count;
            element_having_max_freq = arr[i];
        }
    }

    return element_having_max_freq;
}

// Driver code
int main()
{
    int arr[] = {40, 50, 30, 40, 50, 30, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mostFrequent(arr, n);
    return 0;
}