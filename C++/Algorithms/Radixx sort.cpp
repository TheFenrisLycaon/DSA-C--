// we generraly used comparison based sorting algos but their complexity can only b eoptimised to O(nlogn) in worst case
// Radix sort gives the O(d*(n+b)) time where b is the base for representing numbers, and k is the maximum possible value

#include <iostream>
using namespace std;

int findMax(int a[], int n)
{
	int mx = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > mx)
			mx = a[i];
	return mx;
}

void SortCounter(int a[], int n, int expr)
{
	int output[n];
	int i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[(a[i] / expr) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / expr) % 10] - 1] = a[i];
		count[(a[i] / expr) % 10]--;
	}

	for (i = 0; i < n; i++)
		a[i] = output[i];
}

void radixsort(int a[], int n)
{

	int m = findMax(a, n);

	for (int expr = 1; m / expr > 0; expr *= 10)
		SortCounter(a, n, expr);
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main()
{
	int a[] = {701, 49, 394, 22, 45, 257};
	int n = sizeof(a) / sizeof(a[0]);

	radixsort(a, n);
	print(a, n);
	return 0;
}
