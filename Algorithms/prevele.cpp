#include <bits/stdc++.h>

void pgreater(int arr[], int n)
{
    std ::stack<int> s;
    s.push(arr[0]);
    std ::cout << "-1"
               << " ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();
            
        int pg = (s.empty()) ? -1 : s.top();
        std ::cout << pg << " ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {12, 14, 10, 30, 20};
    int n = 5;
    pgreater(arr, n);
    return 0;
}
