from typing import *


class Solution:
    def count(self, N: int, A: List[int], X: int):
        res = 9223372036854775807
        curr = 0
        for i in range(31, -1, -1):
            if (X >> i) & 1:
                curr |= 1 << i
                continue
            temp = curr | (1 << i)
            k = len(list(filter(lambda x: x & temp == temp, A)))
            res = min(res, N - k)
        return res


if __name__ == "__main__":
    for _ in range(int(input())):
        N, X = map(int, input().strip().split())
        A = list(map(int, input().strip().split()))
        ob = Solution()
        res = ob.count(N, A, X)
        print(res)
