from functools import reduce
from typing import *


class Solution:
    def subsets(self, A: List[int]) -> List[List[int]]:
        return sorted(
            reduce(
                lambda result, x: result + [subset + [x] for subset in result],
                A,
                [[]],
            )
        )


if __name__ == "__main__":
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        A = list(map(int, input().strip().split()))
        ob = Solution()
        result = ob.subsets(A)
        for i in range(len(result)):
            for j in range(len(result[i])):
                print(result[i][j], end=" ")
            print()
