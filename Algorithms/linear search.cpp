#include <iostream>
using namespace std;
int main()
{
  int list[100],size,i,search_el;

  cout<<"Enter size of the list: ";
  cin>>size;

  cout<<"Enter elements of the list: ";
  for(i = 0; i < size; i++)
  cin>>list[i];

  cout<<"Enter the element to be search: ";
  cin>>search_el;
  
  
  for(i = 0; i < size; i++)
  {
     if(search_el == list[i])
     {
        cout<<"Element is found at "<< i+1 <<" place in the list";
        break;
     }
  }
  if(i == size)
     cout<<"Element is not present in the list";
  
}