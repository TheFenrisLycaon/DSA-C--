class Solution(object):
    def copyRandomList(self, head):
        p = head
        while p is not None:
            next = p.next
            copy = RandomListNode(p.label)
            p.next = copy
            copy.next =  next
            p = next
        p = head
        while p is not None:
            if p.random is not None:
                p.next.random = p.random.next
            p = p.next.next
        p = head
        if p is not None:
            headCopy = p.next
        else:
            headCopy = None
        while p is not None:
            copy = p.next
            p.next = copy.next
            p = p.next
            if p is not None:
                copy.next = p.next
        return headCopy