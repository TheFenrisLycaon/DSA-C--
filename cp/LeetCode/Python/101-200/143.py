class Solution(object):
    def reorderList(self, head):
        if head is None or head.next is None:
            return
        p1, p2 = head, head.next
        while p2 and p2.next:
            p1 = p1.next
            p2 = p2.next.next
        head2 = p1.next
        p1.next = None
        p2 = head2.next
        head2.next = None
        while p2:
            temp = p2.next
            p2.next = head2
            head2 = p2
            p2 = temp
        p1, p2 = head, head2
        while p1:
            temp = p1.next
            p1.next = p2
            p1 = p1.next
            p2 = temp
