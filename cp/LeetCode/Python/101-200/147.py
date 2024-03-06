class Solution(object):
    def insertionSortList(self, head):
        if head is None:
            return None
        helper = ListNode(-1000)
        pre, curr = helper, head
        while curr is not None:
            next_step = curr.next
            while pre.next and pre.next.val < curr.val:
                pre = pre.next
            curr.next = pre.next
            pre.next = curr
            pre = helper
            curr = next_step
        return helper.next
