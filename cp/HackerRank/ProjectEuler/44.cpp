#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
    using namespace std;

void get_pandigit(vector <long long>&v, long n){
        for(long i=1;i<n;i++)
                v.push_back((long long)(i*(3*i-1))/2);
}

int main() {
        long n,k;
        vector <long long> v;
        v.push_back(0);
        scanf("%ld %ld",&n,&k);
        get_pandigit(v,n);
        set <long long> s(v.begin(),v.end());
        set <long long> ans;
        for(long i=1;i<n;i++){
                if((i-k)>0){
                        if(s.find(v[i]+v[i-k])!=s.end())
                                ans.insert(v[i]);
                        if(s.find(v[i]-v[i-k])!=s.end())
                                ans.insert(v[i]);

                }
        }
        for(set<long long>::iterator it=ans.begin();it!=ans.end();it++)
                cout<<*it<<endl;
        return 0;    
}
