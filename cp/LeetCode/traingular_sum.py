from typing import List


class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        res = []
        for i in range(0, len(nums) - 1):
            res.append((nums[i] + nums[i + 1]) % 10)
        return self.triangularSum(res)


x = Solution()
print(x.triangularSum([1, 2, 3, 4, 5]))
