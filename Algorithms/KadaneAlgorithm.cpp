// Kadanes algorithm is used for finding the largest sum contigous algorithm
// eg: arr = [-1, 2,-1,3,-2]
//     output: 4
// explanation: largest sum subarray will be subarray form 2nd element to 4th element.

//Time COmplexity: O(n)
//code in c++

#include <bits/stdc++.h>
using namespace std;

int largestSum(int n, int arr[])
{
    int maxTill[n];
    maxTill[0] = arr[0];
    for (int i = 1; i < n; ++i)
    {
        // compare (maximum subarray ending in i-1 index + i'th element) and i'th element
        // the maximum of both will be the maximum subarray ending in i'th index
        maxTill[i] = max(maxTill[i - 1] + arr[i], arr[i]);
    }
    int ans = maxTill[0];
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, maxTill[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    if (n < 1)
    {
        cout << "Invalid n.";
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Largest Sum Subarray for given array will be: " << largestSum(n, arr);
}