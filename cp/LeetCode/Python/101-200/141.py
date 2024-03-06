class Solution(object):
    def hasCycle(self, head):
        try:
            fast = head.next.next
            slow = head.next
            while fast != slow:
                fast = fast.next.next
                slow = slow.next
            return True
        except:
            return False