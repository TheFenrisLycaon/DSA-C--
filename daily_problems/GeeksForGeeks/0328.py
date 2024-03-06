from typing import *


class Solution:
    def swapBits(self, X, P1, P2, N):
        xor = ((X >> P1) & ((1 << N) - 1)) ^ ((X >> P2) & ((1 << N) - 1))
        xor = (xor << P1) | (xor << P2)
        return X ^ xor


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        obj = Solution()
        X, P1, P2, N = map(int, input().split())
        print(obj.swapBits(X, P1, P2, N))
