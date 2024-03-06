from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        length, curr = 1, head
        while curr:
            length += 1
            curr = curr.next
        length -= k
        v1, v2 = head, head
        while length > 1:
            length -= 1
            v1 = v1.next
        while k > 1:
            k -= 1
            v2 = v2.next
        v1.val, v2.val = v2.val, v1.val
        return head
