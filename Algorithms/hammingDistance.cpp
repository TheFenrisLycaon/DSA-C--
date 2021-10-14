#include<bits/stdc++.h>

using namespace std;

int hammingDistance(int x, int y) {
    int ans = x^y;
    int count = 0;
    while(ans>0){
        count++;
        ans = ans & (ans-1);
    }
    return count;
}

int main(){
    int a, b;
    cout<<"Enter a number: ";
    cin>>a;
    cout<<"Enter another number: ";
    cin>>b;
    cout<<"Hamming Distance between two given numbers is : "<<hammingDistance(a,b);
}