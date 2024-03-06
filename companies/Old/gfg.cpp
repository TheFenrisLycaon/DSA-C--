int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
        int dino[n1 + 1][n2 + 1][n3 + 1];
        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                for (int k = 0; k <= n3; k++)
                {
                    if (i == 0 || j == 0 || k == 0)
                        dino[i][j][k] = 0;
                    else
                    {
                        if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                            dino[i][j][k] = 1 + dino[i - 1][j - 1][k - 1];
                        else
                            dino[i][j][k] = max({dino[i - 1][j][k], dino[i][j - 1][k], dino[i][j][k - 1]});
                    }
                }
            }
        }
        return dino[n1][n2][n3];
}