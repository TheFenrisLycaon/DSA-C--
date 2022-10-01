// Problem Statement: Rotate arr[] of size n by d elements.

#include <bits/stdc++.h>
using namespace std;

// Function to reverse arr[] from index start to end
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to left rotate arr[] of size n by d
void leftRotate(int arr[], int d, int n)
{
    if (d == 0)
        return;

    // in case the rotating factor is greater than array length
    d = d % n;

    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    // Function calling
    leftRotate(arr, d, n);

    // print Array
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}

// Example :
// Let the array be arr[] = [1, 2, 3, 4, 5, 6, 7], d =2 and n = 7
// A = [1, 2] and B = [3, 4, 5, 6, 7]

// Reverse A, we get ArB = [2, 1, 3, 4, 5, 6, 7]
// Reverse B, we get ArBr = [2, 1, 7, 6, 5, 4, 3]
// Reverse all, we get (ArBr)r = [3, 4, 5, 6, 7, 1, 2]
