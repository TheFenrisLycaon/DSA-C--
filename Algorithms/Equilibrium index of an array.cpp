// The complexity of this approach is O(n)

#include <bits/stdc++.h>
using namespace std;

int equi(int a[], int n)
{
	if (n == 1)
		return (0);
	int front[n] = { 0 };
	int back[n] = { 0 };

	
	for (int i = 0; i < n; i++) {
		if (i) {
			front[i] = front[i - 1] + a[i];
		}
		else {
			front[i] = a[i];
		}
	}

	
	for (int i = n - 1; i > 0; i--) {
		if (i <= n - 2) {
			back[i] = back[i + 1] + a[i];
		}
		else {
			back[i] = a[i];
		}
	}

	
	for (int i = 0; i < n; i++) {
		if (front[i] == back[i]) {
			return i;
		}
	}
	return -1;

	
}


int main()
{
	int arr[] = { 50, 40, 10, 70, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The first index required is "
		<< equi(arr, n) << "\n";
	return 0;
}
