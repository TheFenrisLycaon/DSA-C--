class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        def util(arr, res=0, cur=0):
            for num in arr:
                cur = max(num, num + cur)
                res = max(res, cur)
            return res

        return (
            ((k - 2) * max(sum(arr), 0) + util(arr * 2)) % (10**9 + 7)
            if k > 1
            else util(arr) % (10**9 + 7)
        )
