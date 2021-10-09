/// time complexity - O(n), auxiliary space requirement - O(1), this finds the result in single traversal of array
#include<iostream>
#include<array>
using namespace std;

int secondLargest(int a[],int n)
{
    int i,res=-1, largest=0;
    for( i=1;i<n;i++)
    {
        if(a[i]>a[largest])
        {
            res=largest;
            largest=i;
        }
        else if(a[i]<a[largest])
        {
            if(res==-1 || a[res]<a[i])
                res=i;
        }

    }
    return res;
}

int main()
{
    int a[]={5,8,20,10};
    int index=secondLargest(a,4);
    cout<<a[index]<<endl;
    return 0;
}
