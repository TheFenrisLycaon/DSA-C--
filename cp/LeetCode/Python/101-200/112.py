class Solution(object):
    def hasPathSum(self, root, sum):
        if root is None:
            return False
        sum = sum - root.val
        if sum == 0 and root.left is None and root.right is None:
            return True
        left = self.hasPathSum(root.left, sum)
        right = self.hasPathSum(root.right, sum)
        return (left or right)
