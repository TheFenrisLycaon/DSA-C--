class Solution(object):
    def rob(self, nums):

        prevMax = currMax = 0
        for num in nums:
            temp = currMax
            currMax = max(prevMax + num, currMax)
            prevMax = temp
        return currMax
