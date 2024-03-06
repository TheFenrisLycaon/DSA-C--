// K largest elements

#include <bits/stdc++.h>

int main()
{
    int arr[] = {5, 15, 10, 20, 8};
    int k = 2;
    int n = 5;
    std ::priority_queue<int, std ::vector<int>, std ::greater<int>> pq(arr, arr + n);
    for (int i = 0; i < n - k; i++)
    {
        pq.pop();
    }
    while (!pq.empty())
    {
        std ::cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
