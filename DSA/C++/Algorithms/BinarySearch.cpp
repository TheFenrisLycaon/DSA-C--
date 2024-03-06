#include <bits/stdc++.h>

int binarySearch(int arr[], int n, int target) // binary search function
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // using mid=(low+high)/2 might cause integer overflow
        if (arr[mid] == target)
        {
            // returns index of target in a non-decreasing sorted array
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1; // removing right half from search space
        }
        else //(arr[mid]<target)
        {
            low = mid + 1; // removing left half from search space
        }
    }
    // returns -1 if element is not found
    return -1;
}

int main()
{
    int n = 5;
    int arr[] = {1, 3, 6, 7, 11};
    int target = 7;
    if (binarySearch(arr, n, target) != -1)
    {
        std :: cout << "Element X=" << target << " is at the " << binarySearch(arr, n, target) + 1 << "-th position\n";
    }
    else
    {
        std :: cout << "Element X=" << target << " not found in the given array\n";
    }
    return 0;
}
