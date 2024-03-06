class Solution(object):
    def findPeakElement(self, nums):
        start, end = 0, len(nums) - 1
        while start < end:
            mid = (start + end) / 2
            if nums[mid] < nums[mid+1]:
                start = mid + 1
            else:
                end = mid
        return start
