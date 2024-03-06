class Solution(object):
    def sumNumbers(self, root):
        if root is None:
            return 0
        res = 0
        queue = [(root, root.val)]
        while len(queue) > 0:
            curr, curr_value = queue.pop(0)
            if curr.left is None and curr.right is None:
                res += curr_value
                continue
            if curr.left:
                queue.append((curr.left, curr_value * 10 + curr.left.val))
            if curr.right:
                queue.append((curr.right, curr_value * 10 + curr.right.val))
        return res
