from typing import *

RYTE, DOWN = 1, 2


class Solution:
    def FindWays(self, maze):
        n = len(maze)

        def initialize():
            return [[0] * n for _ in range(n)]

        def mod(p):
            return p % 1000000007

        d = initialize()
        d[0][0] = maze[0][0]

        p = initialize()
        p[0][0] = 1

        for j in range(1, n):
            if maze[0][j - 1] == DOWN:
                break
            d[0][j] = d[0][j - 1] + maze[0][j]
            p[0][j] = 1

        for i in range(1, n):
            if maze[i - 1][0] == RYTE:
                break
            d[i][0] = d[i - 1][0] + maze[i][0]
            p[i][0] = 1

        for i in range(1, n):
            for j in range(1, n):
                if maze[i - 1][j] != RYTE and p[i - 1][j]:
                    d[i][j] = d[i - 1][j] + maze[i][j]
                    p[i][j] = p[i - 1][j]
                if maze[i][j - 1] != DOWN and p[i][j - 1]:
                    d[i][j] = max(d[i][j], d[i][j - 1] + maze[i][j])
                    p[i][j] += p[i][j - 1]

        if not p[-1][-1]:
            return (0, 0)

        return (mod(p[-1][-1]), d[-1][-1])


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        matrix = []
        for _ in range(n):
            cur = list(map(int, input().split()))
            matrix.append(cur)
        obj = Solution()
        ans = obj.FindWays(matrix)
        for _ in ans:
            print(_, end=" ")
        print()
