from typing import *


class Solution:
    def chooseandswap(self, A):
        unique = set()
        for i in range(len(A)):
            smol = A[i]
            unique.add(smol)
            for j in A[i + 1 :]:
                if j < smol and j not in unique:
                    smol = j
            if smol != A[i]:
                break
        if smol == A[i]:
            return A
        temp = A[i]
        res = ""
        for j in range(len(A)):
            flag = True
            if temp == A[j]:
                flag = False
                res += smol
            elif flag and A[j] == smol:
                res += temp
            else:
                res += A[j]
        return res


if __name__ == "__main__":
    ob = Solution()
    t = int(input())
    for _ in range(t):
        A = input()
        ans = ob.chooseandswap(A)
        print(ans)
