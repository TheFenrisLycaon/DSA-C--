//Problem Statement:
// Given an array, print the Next Greater Element (NGE) for every element.
// The Next greater Element for an element x is the first greater element on the right side of x in the array.
// Elements for which no greater element exist, consider the next greater element as -1.

//Example:
// For the input array [4, 5, 2, 25], the next greater elements for each element are as follows.
// Element       NGE
//    4      -->   5
//    5      -->   25
//    2      -->   25
//    25     -->   -1

#include<bits/stdc++.h>
using namespace std;

//Function to find the next greater element for each element of the array.
vector<long long> nextLargerElement(vector<long long> arr, int n){

        vector<long long>ans(n,-1); //for storing NGE of each element

        stack<pair<long long,int>>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>st.top().first){
                ans[st.top().second]=arr[i];
                st.pop();
            }
            st.push(make_pair(arr[i],i));
        }

        return ans;
}
int main()
{
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;

	return 0;
}
