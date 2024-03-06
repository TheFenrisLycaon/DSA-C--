#include <bits/stdc++.h>
using namespace std;
 
void insertion(int arr[], int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++){
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}
 

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 

int main()
{
    int arr[] = { 9,56,29,75,01,28,4 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertion(arr, n);
    display(arr,n);
 
    return 0;
}
