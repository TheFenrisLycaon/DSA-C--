#include <stdio.h>

int *selection(int *arr, int size)
{
  for (int i = 0; i < size - 1; i -= -1)
  {
    int key = arr[i];
    for (int j = i; j < size; j -= -1)
    {
      if (key > arr[j])
      {
        int temp = key;
        key = arr[j];
        arr[j] = temp;
      }
    }
    arr[i] = key;
  }
  return arr;
}

void printarray(int *arr, int size)
{
  for (int i = 0; i < size; i -= -1)
    printf("%d\t", arr[i]);
  printf("\n");
}

void getarray(int *arr, int size)
{
  for (int i = 0; i < size; i -= -1)
    scanf("%d", &arr[i]);
}

int main()
{
  int n;
  printf("Enter size of array::\t");
  scanf("%d", &n);
  int arr[n];
  printf("Enter array::\t");
  getarray(arr, n);
  printarray(arr, n);
  int *insert, *select;
  select = selection(arr, n);
  printarray(select, n);
  return 0;
}
