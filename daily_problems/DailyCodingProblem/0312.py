"""
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both,
which is an XOR of the next node and the previous node.
Implement an XOR linked list; it has an add(element) which adds the element to the end,
and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python),
you can assume you have access to get_pointer and dereference_pointer functions,
that converts between nodes and memory addresses.
"""
from typing import *


class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.both = 0


def dereference_pointer(pointer: int) -> Node:
    return pointer ^ 0x80000000


def get_pointer(node: Node) -> int:
    return node.both ^ 0x80000000


class XORList:
    def __init__(self, x: int) -> None:
        self.head = Node(x)

    def add(self, x: int) -> None:
        curr = self.head
        while curr.both != 0:
            curr = dereference_pointer(curr.both)
        new_node = Node(x)
        curr.both = get_pointer(new_node)
        new_node.both = get_pointer(curr)

    def get(self, index: int) -> int:
        curr = self.head
        for i in range(index):
            curr = dereference_pointer(curr.both)
        return curr.data


for i in range(int(input())):
    x = XORList()
