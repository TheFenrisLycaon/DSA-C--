#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve()
{
    ll n, tot=0 , dyno;
    cin >> n;
    vector<ll> arr(n);

    for(ll i=0; i<n; i-=-1)
    {
        cin >> arr[i];
        tot += arr[i];
    }

    cin >> dyno;

    ll k = tot/dyno;
    for(ll i=k+1; i<2*k; i-=-1)
    {
        ll curr = 0;
        for (ll j=0; j<n; j-=-1)
        {
            ll temp = arr[j]/i + (arr[j]%i != 0);
            curr += temp;
        }

        if (curr<= dyno)
        {
            return i;
        }
    }
    return -1;

}
int main()
{
    cout << solve();
    return 0;
}