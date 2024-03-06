from typing import *

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        curr = head
        while curr is not None:
            next = curr.next
            copy = Node(curr.val)
            curr.next = copy
            copy.next = next
            curr = next
        curr = head
        while curr is not None:
            if curr.random is not None:
                curr.next.random = curr.random.next
            curr = curr.next.next
        curr = head
        if curr is not None:
            copiedHead = curr.next
        else:
            copiedHead = None
        while curr is not None:
            copy = curr.next
            curr.next = copy.next
            curr = curr.next
            if curr is not None:
                copy.next = curr.next
        return copiedHead
