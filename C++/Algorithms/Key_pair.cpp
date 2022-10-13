#include<bits/stdc++.h>
using namespace std;
bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    set<int> s;
        int c=-1;
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            int temp=x-arr[i];
            if(s.find(temp)!=s.end())
            {
               return 1;
            }
        }
	    return 0;
 }   


int main()
{
    
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        bool ans=hasArrayTwoCandidates(arr,n,x);
        cout<<(ans ? "Yes\n" : "No\n");
    
    return 0;
}

