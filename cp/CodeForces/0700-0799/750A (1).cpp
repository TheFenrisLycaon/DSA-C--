//code by Nikhil Nagrale
//nikhilnagrale2 on EveryPlatform
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int sum=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        sum+=(5*i);
        if(sum+k>240)
        break;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

//simple C++ code:24067296 https://codeforces.com/contest/750/submission/24067296
//shorter but harder C++ code: 24067301 https://codeforces.com/contest/750/submission/24067301