class Solution(object):
    def levelOrderBottom(self, root):
        if root is None:
            return []
        stack = [[root]]
        res = []
        while len(stack) > 0:
            top = stack.pop()
            res.insert(0, [t.val for t in top])
            temp = []
            for node in top:
                if node.left is not None:
                    temp.append(node.left)
                if node.right is not None:
                    temp.append(node.right)
            if len(temp) > 0:
                stack.append(temp)
        return res
