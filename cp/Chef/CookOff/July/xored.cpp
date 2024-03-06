#include<bits/stdc++.h>
using namespace std;
int main(){
    int t ,n;
    cin>>t;
    while(t--){
        cin >> n;
        int max = -1000;
        int a[n];
        for (int i=0; i<n; i++){
            cin>>a[i];
            if (a[i]>max){
                max = a[i];
            }
        }
        cout<<max<<endl;
    }
}