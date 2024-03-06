class Solution(object):
    def detectCycle(self, head):
        try:
            fast = head.next.next
            slow = head.next
            while fast != slow:
                fast = fast.next.next
                slow = slow.next
        except:
            return None
        slow = head
        while fast != slow:
            fast = fast.next
            slow = slow.next
        return fast
