class Solution(object):
    def minDepth(self, root):
        if root is None:
            return 0
        queue = [root]
        depth, rightMost = 1, root
        while len(queue) > 0:
            node = queue.pop(0)
            if node.left is None and node.right is None:
                break
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
            if node == rightMost:
                depth += 1
                if node.right is not None:
                    rightMost = node.right
                else:
                    rightMost = node.left
        return depth
