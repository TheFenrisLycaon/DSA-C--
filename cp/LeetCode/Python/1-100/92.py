class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if not head or n == m: return head
        p = dummy = ListNode(0)
        dummy.next = head
        for _ in range(m - 1):
            p = p.next
        tail = p.next
        
        for _ in range(n - m):
            temp = p.next
            p.next = tail.next
            tail.next = tail.next.next
            p.next.next = temp
        return dummy.next