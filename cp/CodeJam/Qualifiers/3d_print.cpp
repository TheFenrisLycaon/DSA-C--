#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, total = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int a = 1, i = 0, g = 1;
        while (a <= n)
        {
            if (arr[i] >= a)
            {
                a++;
                i++;
                total++;
            }
            else
            {
                a++;
                i++;
            }
        }
        cout << "Case #" << g << ": ";
        cout << total << endl;
        g++;
    }
    return 0;
}