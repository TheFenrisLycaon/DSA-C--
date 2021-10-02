#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int start, int mid, int end)
{
    vector<int> temp(end-start+1);
    int i=start,j=mid+1,k=0;
    while(i<=mid && j<=end)
    {
        if(v[i]<=v[j])
        {
            temp[k++]=v[i++];
        }
        else
        {
            temp[k++]=v[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=v[i++];
    }
    while(j<=end)
    {
        temp[k++]=v[j++];
    }
    for(int i=start;i<=end;i++)
    {
        v[i]=temp[i-start];
    }
}


void mergesort(vector<int> &v, int start, int end)
{
    if(start>=end)
        return;
    int mid=start+(end-start)/2;
    mergesort(v,start,mid);
    mergesort(v, mid+1, end);
    merge(v,start,mid,end);
}

int main() {
    vector<int> v{1,-1,0,9,-26,76,22,73,63};
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergesort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
