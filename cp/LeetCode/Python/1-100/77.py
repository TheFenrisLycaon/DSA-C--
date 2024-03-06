class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        nums = [_ for _ in range(1,n+1)]
        result = []
        combo = []
        n = len(nums)
        for i in range(n):
            combo.append(nums[i])
            self.backtrack(nums[i+1:],combo, result, k)
            combo = []
        return result
    def backtrack(self, nums: List[int], combo: List[int], result: List[List[int]], k: int) -> None:
        if len(combo) == k:
            result.append([_ for _ in combo])
            return
        n = len(nums)
        for i in range(n):
            combo.append(nums[i])
            self.backtrack(nums[i+1:],combo,result,k)
            del combo[-1]
        return