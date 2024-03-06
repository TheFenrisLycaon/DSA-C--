class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        def util(num):
            res = 0
            while num:
                res += 1
                num &= num - 1
            return res

        return util(start ^ goal)


x = Solution()
print(x.minBitFlips(3,4))
