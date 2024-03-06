#include <bits/stdc++.h>
#define ll long long
#define double long double
#define vi vector<int>
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair

using namespace std;

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return (a.second <= b.second);
}

int MinSig(vector<pair<ll, ll>> &segments)
{
    vector<ll> points;
    sort(segments.begin(), segments.end(), cmp);
    for (int x = 0; x < segments.size() - 1;)
    {
        bool found = false;
        points.pb(segments[x].ss);
        for (int y = x + 1; y < segments.size(); y++)
        {
            if (segments[y].ff > segments[x].ss)
            {
                x = y;
                found = true;
                break;
            }
        }
        if (!found)
            break;
    }
    int res = points.size();
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (int x = 0; x < n; x++)
    {
        ll temp1, temp2;
        cin >> temp1 >> temp2;
        v.pb(mp(temp1, temp2));
    }
    sort(v.begin(), v.end(), cmp);
    int res = MinSig(v);
    cout << res << endl;
}