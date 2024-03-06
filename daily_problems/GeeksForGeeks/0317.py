from typing import *


class Solution:
    def kvowelwords(self, N: int, K: int) -> int:
        mod = 10**9 + 7
        dp = [1]
        dpp = [1]
        for _ in range(K):
            dpp.append((dpp[-1] * 5) % mod)
        for i in range(1, N + 1):
            tot = 0
            for j in range(min(i + 1, K + 1)):
                count = dpp[j]
                if i > j:
                    count = (count * 21 * dp[i - j - 1]) % mod
                tot = (tot + count) % mod
            dp.append(tot)
        return dp[-1]


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        N, K = map(int, input().split())
        ob = Solution()
        ans = ob.kvowelwords(N, K)
        print(ans)
