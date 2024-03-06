class Solution(object):
    def __init__(self):
        self.node = None

    def sortedListToBST(self, head):
        if head is None:
            return head
        size = 0
        pos = self.node = head
        while pos is not None:
            pos = pos.next
            size += 1
        return self.inorderHelper(0, size - 1)

    def inorderHelper(self, start, end):
        if start > end:
            return None
        mid = (start + end) / 2
        left = self.inorderHelper(start, mid - 1)
        root = TreeNode(self.node.val)
        root.left = left
        self.node = self.node.next
        root.right = self.inorderHelper(mid + 1, end)
        return root
