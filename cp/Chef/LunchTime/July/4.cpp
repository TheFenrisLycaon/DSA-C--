#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t, n, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> arr1(n), arr2(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }
        vector<ll> v;
        ll c, mi = INT_MAX;
        for (i = 0; i < n; i++)
        {
            c = arr1[0] + arr2[i];
            c = c % n;
            mi = min(mi, c);
        }
        for (i = 0; i < n; i++)
        {
            c = arr1[0] + arr2[i];
            c = c % n;
            if (c == mi)
            {
                v.push_back(i);
            }
        }
        if (v.size() == 1)
        {
            ll a = v[0];
            ll p = 0;
            for (ll j = a; j < n; j++, p++)
            {
                cout << (arr1[p] + arr2[j]) % n << " ";
            }
            for (ll j = 0; j < a; j++, p++)
            {
                cout << (arr1[p] + arr2[j]) % n << " ";
            }
        }
        else
        {
            vector<ll> array1;
            vector<ll> array2;
            ll a = v[0], p = 0;
            //cout<<a<<" <= \n";
            for (ll j = a; j < n; j++, p++)
            {
                //cout<<(arr1[p]+arr2[j])%n<<" ";
                array1.push_back((arr1[p] + arr2[j]) % n);
            }
            for (ll j = 0; j < a; j++, p++)
            {
                //cout<<(arr1[p]+arr2[j])%n<<" ";
                array1.push_back((arr1[p] + arr2[j]) % n);
            }
            a = v[1];
            p = 0;
            //cout<<a<<" <= \n";
            for (ll j = a; j < n; j++, p++)
            {
                //cout<<(arr1[p]+arr2[j])%n<<" ";
                array2.push_back((arr1[p] + arr2[j]) % n);
            }
            for (ll j = 0; j < a; j++, p++)
            {
                //cout<<(arr1[p]+arr2[j])%n<<" ";
                array2.push_back((arr1[p] + arr2[j]) % n);
            }
            if (array1 < array2)
            {
                for (i = 0; i < n; i++)
                {
                    cout << array1[i] << " ";
                }
            }
            else
            {
                for (i = 0; i < n; i++)
                {
                    cout << array2[i] << " ";
                }
            }
        }
        cout << "\n";
    }
}