from typing import *


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        curr = head = ListNode()
        while True:
            if list1 == None and list2 == None:
                break
            elif list1 == None:
                curr.next = ListNode(list2.val)
                list2 = list2.next
            elif list2 == None:
                curr.next = ListNode(list1.val)
                list1 = list1.next
            elif list1.val <= list2.val:
                curr.next = ListNode(list1.val)
                list1 = list1.next
            else:
                curr.next = ListNode(list2.val)
                list2 = list2.next
            curr = curr.next
        return head.next
