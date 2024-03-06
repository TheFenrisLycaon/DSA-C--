class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy_head = ListNode(-1)
        dummy_head.next = head
        cur, prev_of_removal = dummy_head, dummy_head
        while cur.next != None:
            if n <= 0:
                prev_of_removal = prev_of_removal.next
            cur = cur.next
            n -=1
        n_th_node = prev_of_removal.next
        prev_of_removal.next = n_th_node.next
        del n_th_node
        return dummy_head.next
