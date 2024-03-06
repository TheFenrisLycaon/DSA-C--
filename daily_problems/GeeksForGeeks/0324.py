from typing import *


class Solution:
    def findMinInsertions(self, S):
        n = len(S)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if S[i] == S[j]:
                    dp[i][j] = 0 if j - i == 1 else dp[i + 1][j - 1]
                else:
                    dp[i][j] = min(1 + dp[i + 1][j], 1 + dp[i][j - 1])
        return dp[0][n - 1]


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S = input().strip()
        ob = Solution()
        print(ob.findMinInsertions(S))
