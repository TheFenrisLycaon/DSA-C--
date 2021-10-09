/// K largest elements
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int arr[]={5,15,10,20,8};
    int k=2;
    int n=5;
    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+n);
    for(int i=0;i<n-k;i++)
    {
        pq.pop();
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
