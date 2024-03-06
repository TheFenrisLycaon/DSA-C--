#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
const int MAXN = 3e5 + 5;
int tree[4 * MAXN];
int Arr[MAXN];
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = Arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}
int query(int node, int start, int end, int l, int r)
{
    if (r < start or end < l)
    {
        return INT_MAX;
    }
    if (l <= start and end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return min(p1, p2);
}
int solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int k; 
    cin >> k;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1)
        {
            int x = a[i] - 1;
            int y = b[i] - 1;
            int z = x / y;
            if (x % y)
            {
                z++;
            }
            c[i] = 2 * z - 1;
        }
        else
        {
            int x = a[i] - 2;
            int y = b[i] - 2;
            int z = x / y;
            if (x % y)
            {
                z++;
            }
            c[i] = 2 * z - 1;
        }
        Arr[i] = c[i];
    }
    vector<int> v;
    build(1, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i + k - 1 >= n)
            break;
        v.pb(query(1, 0, n - 1, i, i + k - 1));
    }
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
signed main()
{
    solve();
    return 0;
}
