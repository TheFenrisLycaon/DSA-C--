//code by Nikhil Nagrale
//nikhilnagrale2 on EveryPlatform
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int A=0,D=0;
    for(auto x:s){
        if(x=='A') A++;
        else D++;
    }
    if(A>D)
    cout<<"Anton"<<endl;
    else if(D>A)
    cout<<"Danik"<<endl;
    else cout<<"Friendship"<<endl;
    return 0;
}