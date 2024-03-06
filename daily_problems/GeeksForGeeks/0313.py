from typing import *


class Solution:
    def FindWays(self, n, m, blocked_cells):
        dp = [[0 for j in range(m)] for i in range(n)]
        for b in blocked_cells:
            dp[b[0] - 1][b[1] - 1] = -1

        if (dp[0][0] == -1) or (dp[n - 1][m - 1] == -1):
            return 0

        for i in range(n):
            if dp[i][0] == 0:
                dp[i][0] = 1
            else:
                break

        for i in range(1, m):
            if dp[0][i] == 0:
                dp[0][i] = 1
            else:
                break

        for i in range(1, n):
            for j in range(1, m):
                if dp[i][j] == -1:
                    continue
                if dp[i - 1][j] > 0:
                    dp[i][j] = dp[i][j] + dp[i - 1][j]
                if dp[i][j - 1] > 0:
                    dp[i][j] = dp[i][j] + dp[i][j - 1]


        return dp[n - 1][m - 1] % (10**9 + 7)


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, m, k = input().split()
        n = int(n)
        m = int(m)
        k = int(k)
        blocked_cells = []
        for i in range(k):
            a = list(map(int, input().split()))
            blocked_cells.append(a)
        obj = Solution()
        ans = obj.FindWays(n, m, blocked_cells)
        print(ans)
