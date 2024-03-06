#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >>t;
    while (t--){
        int n; cin >> n;
        float arr[n];
        for(int i=0; i<n;i++){
            cin>>arr[n];
        }
        int count;
        for(int i = 0; i<n;i++){
            for (int j = 0;j<n;j++){
                if (i != j){
                    float k = arr[i] - arr[j];
                    if (k/arr[i]<k/arr[j]){
                        count ++;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}