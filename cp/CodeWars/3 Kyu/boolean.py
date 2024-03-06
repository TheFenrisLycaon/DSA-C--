from itertools import product


def solve(s, ops):
    dp = [[[0, 0] for _ in range(len(s))] for _ in range(len(s))]
    for i in range(len(s)):
        if s[i] == "t":
            dp[i][i][1] = 1
        else:
            dp[i][i][0] = 1
    for k in range(1, len(s)):
        for i in range(len(s) - k):
            j = i + k
            for m in range(i, j):
                if ops[m] == "^":
                    dp[i][j][0] += (
                        dp[i][m][0] * dp[m + 1][j][0] + dp[i][m][1] * dp[m + 1][j][1]
                    )
                    dp[i][j][1] += (
                        dp[i][m][0] * dp[m + 1][j][1] + dp[i][m][1] * dp[m + 1][j][0]
                    )
                elif ops[m] == "|":
                    dp[i][j][0] += dp[i][m][0] * dp[m + 1][j][0]
                    dp[i][j][1] += (
                        dp[i][m][0] * dp[m + 1][j][1]
                        + dp[i][m][1] * dp[m + 1][j][0]
                        + dp[i][m][1] * dp[m + 1][j][1]
                    )
                else:
                    dp[i][j][0] += (
                        dp[i][m][0] * dp[m + 1][j][1]
                        + dp[i][m][1] * dp[m + 1][j][0]
                        + dp[i][m][0] * dp[m + 1][j][0]
                    )
                    dp[i][j][1] += dp[i][m][1] * dp[m + 1][j][1]
    return dp[0][len(s) - 1][1]