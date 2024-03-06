from collections import defaultdict
from math import log
from typing import *


def maximumPoints(n: int, a: List[int]):
    points = defaultdict(int)
    maxi = 0
    for num in a:
        points[num] += num
        maxi = max(maxi, num)

    beta = alpha = 0
    n = len(points)
    if maxi < n + n * log(n, 2):
        alpha = points[1]
        for num in range(2, maxi + 1):
            beta, alpha = alpha, max(alpha, beta + points[num])
    else:
        elements = sorted(points.keys())
        alpha = points[elements[0]]
        for i in range(1, len(elements)):
            curr = elements[i]
            if curr == elements[i - 1] + 1:
                beta, alpha = alpha, max(alpha, beta + points[curr])
            else:
                beta, alpha = alpha, alpha + points[curr]

    return alpha
