#include<iostream>
#include<array>
#include<stack>
using namespace std;
void pgreater(int arr[],int n)
{
    stack<int> s;
    s.push(arr[0]); cout<<"-1"<<" ";
    for(int i=1;i<n;i++)
    {
        while(s.empty()==false && s.top()<=arr[i])
            s.pop();
        int pg=(s.empty())?-1:s.top();
        cout<<pg<<" ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[]={12,14,10,30,20};
    int n=5;
    pgreater(arr,n);
    return 0;
}
