// Question: https://codeforces.com/problemset/problem/1370/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << n/2 << endl;
    }
    return 0;
}

//Let the maximum gcd be equal to g.
// Since the two numbers in a pair are distinct,
// one of them must be >g and
//both of them must be divisible by g.
// The smallest multiple of g, greater than g, is 2⋅g.
//Since each number in the pair must be ≤n,
// we must have 2⋅g≤n, or g≤⌊n2⌋.
//We can achieve g=⌊n2⌋, by choosing ⌊n2⌋ and 2⋅⌊n2⌋.
