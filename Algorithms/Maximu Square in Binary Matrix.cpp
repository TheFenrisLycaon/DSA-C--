// to find the maximum area of the square in a binary matrix

#include <bits/stdc++.h>

// helper function
// bottom up approach
int minimalSq(std ::vector<std ::vector<int>> &matrix, int m, int n)
{
    std ::vector<std ::vector<int>> dp(m, std ::vector<int>(n, 0));
    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            // if it is last row or a last column then the maximum area would be either 0 or 1
            if (i == m - 1 || j == n - 1)
                dp[i][j] = matrix[i][j];
            //if at any index the value is 0 then the square at that position would be zero
            else if (matrix[i][j] == 0)
                dp[i][j] = 0;
            //else we will check all the adjacent index i.e right, down, down right diagonal and find min val + 1
            else
            {
                int mn = std ::min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
                dp[i][j] = mn + 1;
            }
            ans = std ::max(ans, dp[i][j]); // update the ans with maximum value
        }
    }

    return ans * ans;
}

int main()
{
    int m, n;
    std ::cout << "Enter the number of rows and columns::";
    std ::cin >> m >> n;

    std ::vector<std ::vector<int>> matrix(m, std ::vector<int>(n));

    //create the binary matrix
    std ::cout << "Enter the elements of the matrix::";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            std ::cin >> matrix[i][j];

    std ::cout << minimalSq(matrix, m, n);
    return 0;
}
