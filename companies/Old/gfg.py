def LCSof3(n1, n2, n3):

    dp = [[[-1 for n1 in range(100)] for n2 in range(100)] for n3 in range(100)]

    if n1 == -1 or n2 == -1 or n3 == -1:
        return 0

    if dp[n1][n2][n3] != -1:
        return dp[n1][n2][n3]

    if A[n1] == B[n2] and B[n2] == C[n3]:
        dp[n1][n2][n3] = 1 + LCSof3(n1 - 1, n2 - 1, n3 - 1)
        return dp[n1][n2][n3]

    else:
        dp[n1][n2][n3] = max(
            max(LCSof3(n1 - 1, n2, n3), LCSof3(n1, n2 - 1, n3)), LCSof3(n1, n2, n3 - 1)
        )

        return dp[n1][n2][n3]
