class Solution(object):
    def __init__(self):
        self.result = -2147483647
    def maxPathSum(self, root):
        self.getNodeMaxValue(root)
        return self.result
    def getNodeMaxValue(self, node):
        if node is None:
            return 0
        lresult = self.getNodeMaxValue(node.left)
        rresult = self.getNodeMaxValue(node.right)
        self.result = max(lresult + rresult + node.val, self.result)
        ret = node.val + max(lresult, rresult)
        if ret > 0:
            return ret
        return 0
