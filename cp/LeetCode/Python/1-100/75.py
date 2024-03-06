class Solution:
    def sortColors(self, nums: List[int]) -> None:
        i = k = 0
        n = len(nums)
        j = n-1
        while k < n and i < j:
            if nums[k] == 0:
                if k > i:
                    nums[i], nums[k] = nums[k], nums[i]
                    i += 1
                else:
                    k += 1
            elif nums[k] == 2:
                if k < j:
                    nums[j], nums[k] = nums[k], nums[j]
                    j -= 1
                else:
                    k += 1
            else:
                k += 1
