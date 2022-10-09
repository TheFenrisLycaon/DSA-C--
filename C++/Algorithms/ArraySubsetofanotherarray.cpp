#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    long long k=1e5;
    long long hsh1[k+1]={0};
    long long hsh2[k+1]={0};
     for(int i=0;i<n;i++){
         hsh1[a1[i]]++;
     }
     for(int i=0;i<m;i++){
         hsh2[a2[i]]++;
     }
     int c=-1;
     for(int j=0;j<m;j++){
         if(hsh1[a2[j]]<hsh2[a2[j]])
         {
            c=1;
             break;
         }
     }
     string Y="Yes";
     string N="No";
     if(c==-1)
     return Y;
     else if(c==1)
     return N;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a1[n],a2[m];
        for(int i=0;i<n;i++)
        cin>>a1[i];
        for(int i=0;i<m;i++)
        cin>>a2[i];
        cout<<isSubset(a1,a2,n,m)<<endl;
    }
    return 0;
}

