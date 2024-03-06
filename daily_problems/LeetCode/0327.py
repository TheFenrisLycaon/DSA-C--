from typing import *

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        return [
            x[0]
            for x in sorted(
                [(idx, sum(mat[idx])) for idx in range(len(mat))], key=lambda z: z[1]
            )[:k]
        ]
