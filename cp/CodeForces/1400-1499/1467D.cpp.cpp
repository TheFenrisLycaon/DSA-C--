#include<bits/stdc++.h>
using namespace std; 
#define int long long
const int N= 5050, P= 1e9+7;
int paths[N][N];
int a[N], cnt[N], pos[N], nPos[N];
 
void fillPaths(int n, int k) {
    for(int k1=0; k1<=k; k1++)
        for(int i=1; i<=n; i++) 
            if(k1==0) paths[i][k1]=1;
            else paths[i][k1]=(paths[i-1][k1-1]+paths[i+1][k1-1])%P;
}
 
 
signed main() {
    int n, k, q; 
    scanf("%lli %lli %lli", &n, &k, &q);
    for(int i=1; i<=n; i++)
        scanf("%lli", a+i);
    
    fillPaths(n, k);
    for(int i=1; i<=n; i++) pos[i]=1;
    
    for(int i=0; i<=k; i++) {
        for(int j=1; j<=n; j++) {
            cnt[j]= (cnt[j]+pos[j]*paths[j][k-i])%P;
            for(int p: {j-1, j+1}) {
                if(p==0 or p==n+1) continue;
                nPos[p]+= pos[j];
            }
        }
 
        for(int j=1; j<=n; j++) {
            pos[j]= nPos[j]%P;
            nPos[j]=0;
        }
    }
 
    int ans= 0;
    for(int j=0; j<=n; j++) 
        ans= (ans+cnt[j]*a[j])%P;
    
    while(q--) {
        int i, x; 
        scanf("%lli %lli", &i, &x);
        ans+= (x-a[i])*cnt[i];
        a[i]= x;
        ans%= P;
        ans= (ans+P)%P;
        printf("%lli\n", ans);
    }
}