class Solution(object):
    def connect(self, root):
        if root is None:
            return
        nodes = [root]
        while len(nodes) != 0:
            next_step = []
            last = None
            for node in nodes:
                if last is not None:
                    last.next = node
                if node.left is not None:
                    next_step.append(node.left)
                if node.right is not None:
                    next_step.append(node.right)
                last = node
            nodes = next_step
