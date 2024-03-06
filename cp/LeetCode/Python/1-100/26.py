class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        nums[:] = list(dict.fromkeys(nums))
        return len(nums)
        
            