class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        i = j = len(nums)-1
        while i > 0 and nums[i-1] >= nums[i]:
            i -= 1
        if i == 0:   
            nums.reverse()
            return 
        k = i - 1    
        while nums[j] <= nums[k]:
            j -= 1
        nums[k], nums[j] = nums[j], nums[k]  
        l, r = k+1, len(nums)-1  
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l +=1 ; r -= 1