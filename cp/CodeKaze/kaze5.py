from typing import *


def largestK(a: List[int], b: List[int], n: int) -> int:
    delta = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

    for i in range(n - 1, -1, -1):
        for j in range(n - 1, -1, -1):
            if a[i] <= b[j]:
                delta[j][i] = delta[j + 1][i + 1] + 1

    maxi = 0

    for i in delta:
        for j in i:
            maxi = max(maxi, j)

    return maxi


for _ in range(int(input())):
    print(
        largestK(
            int(input()),
            list(map(int, input().split())),
            list(map(int, input().split())),
        )
    )
