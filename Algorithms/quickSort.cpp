// program for quick sort implementation

#include<bits/stdc++.h>
using namespace std;


// this function takes the last index value of the array as pivot value and
// rearranges the array such that all the values lower than the pivot value
// lies to the left of it and all the values greater than the pivot value
// lies to the right of it.
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int pivotIndex = low;
	for(int i=low;i<high;i++) {
		if(arr[i]<pivot) {
			swap(arr[pivotIndex], arr[i]);
			pivotIndex++;
		}
	}
	swap(arr[pivotIndex], arr[high]);
	return pivotIndex;
}

// function for quick sort
void quickSort(int arr[], int low, int high) {

	// base condition
	if(low>=high)
		return ;
	else {
		int pivotIndex = partition(arr, low, high);

		// recursive call for left half from the pivotIndex
		quickSort(arr, low, pivotIndex-1);

		// recursive call for right half from the pivotIndex
		quickSort(arr, pivotIndex+1, high);
	}
}

int main() {
	int n;

	// take input the number of elements in the array
	cin>>n;
	int arr[n+1];

	// take input the array
	for(int i=0;i<n;i++)
		cin>>arr[i];

	// sort the array using quick sort
	quickSort(arr, 0, n-1);
	cout<<"sorted array is: "<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}