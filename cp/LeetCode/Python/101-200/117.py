class Solution(object):
    def connect(self, root):
        dummyHead = TreeLinkNode(-1)
        pre = dummyHead
        while root is not None:
            if root.left is not None:
                pre.next = root.left
                pre = pre.next
            if root.right is not None:
                pre.next = root.right
                pre = pre.next
            root = root.next
            if root is None:
                pre = dummyHead
                root = dummyHead.next
                dummyHead.next = None
