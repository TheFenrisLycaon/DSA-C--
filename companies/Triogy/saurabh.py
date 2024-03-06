class Solution:
    def solve(self, A):
        x = 1
        day = 0

        for troops in sorted(A):
            day += (troops // x) * (troops % x == 0) + ((troops + x) // x) * (
                troops % x != 0
            )
            x += 1

        return day


print(Solution().solve([4, 3, 1]))
print(Solution().solve([9, 9]))
