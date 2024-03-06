"""
Given two singly linked lists that intersect at some point,
find the intersecting node.
The lists are non-cyclical.

For example,
given A = 3 -> 7 -> 8 -> 10
and B = 99 -> 1 -> 8 -> 10,
return the node with value 8.

In this example,
assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
"""
from typing import *
from dataclasses import dataclass


@dataclass
class Node:
    value: int
    next: Optional["Node"] = None


class LinkedList:
    def __init__(self):
        self.head = None

    def add(self, value: int):
        node = Node(value)
        if self.head is None:
            self.head = node
        else:
            curr = self.head
            while curr.next is not None:
                curr = curr.next
            curr.next = node

    def __str__(self):
        _str = str(A.head.value)
        curr = A.head
        while curr.next is not None:
            curr = curr.next
            _str += f" -> {curr.value}"
        return _str


def intersection(A: Optional[LinkedList], B: Optional[LinkedList]) -> Optional[Node]:
    currA = A.head
    currB = B.head
    while currA is not None:
        currB = B.head
        while currB is not None:
            if currA.value == currB.value:
                return currA
            currB = currB.next
        currA = currA.next
    return None


if __name__ == "__main__":
    A = LinkedList()
    A.add(3)
    A.add(7)
    A.add(8)
    A.add(10)
    B = LinkedList()
    B.add(99)
    B.add(1)
    B.add(8)
    B.add(10)

    print(intersection(A, B))
