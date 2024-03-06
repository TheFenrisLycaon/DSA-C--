#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 200005;
 
vector<int> G[N];
int a[N], d[N];
int dfn[N], out[N], ck;
map<int, int> mp, c;
void dfs(int u, int fa) {
    dfn[u] = ++ck;
    int tt = c[a[u]];
    c[a[u]]++;
    for (auto v : G[u]) {
        if (v == fa) continue;
        int tmp = c[a[u]];
        dfs(v, u);
        if (c[a[u]] > tmp) {
            d[1]++, d[dfn[v]]--;
            d[out[v] + 1]++;
        }
    }
    out[u] = ck;
    if (c[a[u]] - tt < mp[a[u]]) {
        d[dfn[u]]++, d[out[u] + 1]--;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        if (d[i] == 0) ans++;
    }
    printf("%d\n", ans);
    return 0;
}