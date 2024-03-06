from typing import *


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        back = {c: i for i, c in enumerate(s)}
        begin = end = 0
        res = []
        for i, c in enumerate(s):
            end = max(end, back[c])
            if i == end:
                res.append(end - begin + 1)
                begin = i + 1
        return res
