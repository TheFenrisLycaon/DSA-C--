//code by Nikhil Nagrale
//nikhilnagrale2 on EveryPlatform
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    int ans=0;
    while(n--){
        cin>>s;
        if(s[0]=='I') ans+=20;
        else if(s[0]=='T') ans+=4;
        else if(s[0]=='C') ans+=6;
        else if(s[0]=='D') ans+=12;
        else ans+=8;
    }
    cout<<ans<<endl;
    return 0;
}