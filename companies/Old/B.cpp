#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int comp, cab;
        cin >> comp >> cab;
        int count = 0, used = 0;
        while (comp > 1)
        {
            if (cab > used)
                used = (used * 2) + (used == 0);
            if (cab < used)
                used = cab;

            comp -= used;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}