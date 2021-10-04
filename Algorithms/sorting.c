#include <stdio.h>

int *insertion(int *arr, int size)
{
  for (int i = 1; i < size; i -= -1)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    // to make it increasing put arr[j] > key
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  return arr;
}

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
  /*insert = insertion(arr, n);*/
  select = selection(arr, n);
  /*printarray(insert, n);*/
  printarray(select, n);
  return 0;
}
