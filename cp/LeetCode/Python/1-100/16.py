import sys

class Solution:
    def threeSumClosest(self, nums, target):
       
        nums.sort()

        closest_sum = sys.maxsize
        for num in range(len(nums) - 2):
           
            ptr_first, ptr_last = num + 1, len(nums) - 1

            while ptr_first < ptr_last:
                sum_temp = nums[num] + nums[ptr_first] + nums[ptr_last]
                if abs(target - sum_temp) < abs(target - closest_sum):
                    closest_sum = sum_temp
                if sum_temp > target:
                    ptr_last = ptr_last - 1
                else:
                    ptr_first = ptr_first + 1
        return closest_sum
