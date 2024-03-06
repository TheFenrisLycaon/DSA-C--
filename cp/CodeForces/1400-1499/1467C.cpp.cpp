#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#pragma GCC optimize(2)
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<random>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=300010;
ll a[N],b[N],c[N];
int main()
{
    IO;
    int T=1;
    //cin>>T;
    while(T--)
    {
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        ll sum=0,s1=0,s2=0,s3=0;
        for(int i=1;i<=n1;i++)
        {
            cin>>a[i];
            sum+=a[i];
            s1+=a[i];
        }
        for(int i=1;i<=n2;i++) 
        {
            cin>>b[i];
            sum+=b[i];
            s2+=b[i];
        }
        for(int i=1;i<=n3;i++)
        {
            cin>>c[i];
            sum+=c[i];
            s3+=c[i];
        }
        sort(a+1,a+1+n1);
        sort(b+1,b+1+n2);
        sort(c+1,c+1+n3);
        
        ll res=max(max(sum-2*a[1]-2*b[1],sum-2*a[1]-2*c[1]),sum-2*b[1]-2*c[1]);
        res=max(res,max(sum-2*s1,max(sum-2*s2,sum-2*s3)));
        cout<<res<<'\n';
        
 
    }
    return 0;
}