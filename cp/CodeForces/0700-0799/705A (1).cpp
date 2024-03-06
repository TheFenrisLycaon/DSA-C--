//code by Nikhil Nagrale
//nikhilnagrale2 on EveryPlatform
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    int i=0;
    while(n--){
        i++;
        if(i%2!=0)
            s+="I hate ";
        else s+="I love ";

        if(n==0){
            s+="it ";
        }else s+="that ";
    }
    cout<<s<<endl;
    return 0;
}