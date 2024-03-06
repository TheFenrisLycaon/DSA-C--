class Solution(object):
    def sortedArrayToBST(self, nums):
        return self.getHelper(nums, 0, len(nums) - 1)

    def getHelper(self, nums, start, end):
        if start > end:
            return None
        mid = (start + end) / 2
        node = TreeNode(nums[mid])
        node.left = self.getHelper(nums, start, mid - 1)
        node.right = self.getHelper(nums, mid + 1, end)
        return node
