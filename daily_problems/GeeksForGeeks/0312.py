from typing import *


class Solution:
    def checkMirrorTree(self, n, e, A, B):
        s = []
        q = []

        for i in range(n + 1):
            s.append([])
            queue = []
            q.append(queue)

        for i in range(0, 2 * e, 2):
            s[A[i]].append(A[i + 1])
            q[B[i]].append(B[i + 1])

        for i in range(1, n + 1):
            while len(s[i]) > 0 and len(q[i]) > 0:
                a = s[i][len(s[i]) - 1]
                s[i].pop()
                b = q[i][0]
                q[i].pop(0)
                if a != b:
                    return 0
        return 1


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, e = map(int, input().split())
        A = list(map(int, input().split()))
        B = list(map(int, input().split()))
        ob = Solution()
        print(ob.checkMirrorTree(n, e, A, B))
