from typing import *


class Solution:
    def findHeight(self, N:int, arr: List[int]) -> int:
        dp = [0] * N
        for i in range(N):
            dp[i] = dp[arr[i]] + 1
        return dp[N - 1]


if __name__ == "__main__":
    for _ in range(int(input())):
        ob = Solution()
        print(ob.findHeight(int(input()), list(map(int, input().split()))))
