#include <bits/stdc++.h>
using namespace std;

//returns index of target in a non-decreasing sorted array
//returns -1 if element is not found
int binarySearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; //using mid=(low+high)/2 might cause integer overflow
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1; //removing right half from search space
        }
        else //(arr[mid]<target)
        {
            low = mid + 1; //removing left half from search space
        }
    }
    return -1;
}

int main()
{
    int n = 5;
    int arr[] = {1, 3, 6, 7, 11};
    int target = 7;
    if (binarySearch(arr, n, target) != -1)
    {
        cout << "Element X=" << target << " is at the " << binarySearch(arr, n, target) + 1 << "-th position\n";
    }
    else
    {
        cout << "Element X=" << target << " not found in the given array\n";
    }
    return 0;
}
