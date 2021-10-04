#include <bits/stdc++.h>

int main()
{
  int arr[] = {5, 6, 7, 8, 1, 2, 3, 4, 0, 8, 5, 4, 3, 2, 4, 5, 6, 7, 8, 10};
  int low = 0, high = sizeof(arr) / sizeof(arr[0]);
  int mid = (low + high) / 2;
  int leftSum = INT_MIN, sum = 0;

  int maxLeft;
  for (int i = mid; i > low; i--)
  {
    sum += arr[i];
    if (sum > leftSum)
    {
      leftSum = sum;
      maxLeft = i;
    }
  }

  int rightSum = INT_MIN;
  sum = 0;
  int maxRight;
  for (int i = mid + 1; i <= low; i++)
  {
    sum += arr[i];
    if (sum > leftSum)
    {
      leftSum = sum;
      maxRight = i;
    }
  }

  for (int i = maxLeft; i <= maxRight; i -= -1)
    std::cout << arr[i] << std::endl;
  return 0;
}