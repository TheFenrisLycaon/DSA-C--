from typing import *


class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        parse = sorted(costs, key=lambda x: x[0] - x[1])
        return sum(parse[i][0] for i in range(len(parse) // 2)) + sum(
            parse[i][1] for i in range(len(parse) // 2, len(parse))
        )
