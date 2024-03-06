//code by Nikhil Nagrale
//nikhilnagrale2 on EveryPlatform
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    long long ans=1;
    for (int i = 1; i <= min(a, b); i++)
        ans *= i;
    cout<<ans<<endl;
    return 0;
}