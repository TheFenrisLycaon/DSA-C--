from typing import *


class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        count_a = defaultdict(int)
        count_b = defaultdict(int)
        N = len(tops)
        same = 0

        for i in range(N):
            count_a[tops[i]] += 1
            count_b[bottoms[i]] += 1

            if tops[i] == bottoms[i]:
                same += 1

        for x in range(1,7):
            if (count_a[x] + count_b[x] - same) == N:
                return N - max(count_a[x], count_b[x])

        return -1
