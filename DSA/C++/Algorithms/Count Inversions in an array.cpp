// Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the maximum.
// Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
// we can do this O(n^2) using naive approach but we'll use merge sort to get O(nlogn)

#include <bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
		  int right);

int ms(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left)
	{

		mid = (right + left) / 2;

		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

int merge(int arr[], int temp[], int left, int mid,
		  int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];

			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int main()
{
	int a[] = {22, 11, 7, 45, 98};
	int n = sizeof(a) / sizeof(a[0]);
	int ans = ms(a, n);
	cout << " Number of inversions are " << ans;
	return 0;
}
