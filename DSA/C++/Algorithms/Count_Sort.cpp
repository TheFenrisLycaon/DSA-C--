#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void countSort(int arr[], int n)
{
    int max = *max_element(arr, arr + n);
    int c[max + 1] = {0};
    for (int i = 0; i < n; ++i)
    {
        c[arr[i]]++;
    }
    int i = 0, j = 0;
    while (i < max + 1)
    {
        if (c[i])
        {
            arr[j] = i;
            j++;
            c[i]--;
        }
        else
            i++;
    }
}

int main()
{
    int arr[] = {4, 5, 1, 3, 2};
    int n = 5;

    printArr(arr, n);

    countSort(arr, n);

    printArr(arr, n);
}