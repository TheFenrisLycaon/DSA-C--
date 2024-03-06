from typing import *


class Solution:
    def minRepeats(self, A, B):
        a = len(B) // len(A)
        for x in range(len(A) + 1):
            s = (a + x) * A
            if B in s:
                return a + x
        return -1


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        A = input()
        B = input()
        ob = Solution()
        print(ob.minRepeats(A, B))
