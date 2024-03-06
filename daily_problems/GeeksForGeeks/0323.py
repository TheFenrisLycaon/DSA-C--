import atexit
import io
import sys
from typing import *

"""
Function Arguments :
        @param  : head (given head of linked list), k(value of k)
        @return : None, Just swap the nodes
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def swapkthnode(head: Node, num: int, k: int) -> Node:
    if n<k:
        return head

    if (2 * k - 1) == n:
        return head

    x = head
    x_prev = Node(None)
    for i in range(k - 1):
        x_prev = x
        x = x.next


    y = head
    y_prev = Node(None)
    for i in range(n - k):
        y_prev = y
        y = y.next


    if x_prev is not None:
        x_prev.next = y

    if y_prev is not None:
        y_prev.next = x


    temp = x.next
    x.next = y.next
    y.next = temp

    if k == 1:
        head = y

    if k == n:
        head = x

    return head

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, new_value: int) -> None:
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = new_node


def getNthfromEnd(head: Node, n: int) -> Node:
    curr_node = head
    nth_node = head
    while n:
        if n and curr_node == None:
            return None
        curr_node = curr_node.next
        n -= 1
    while curr_node:
        curr_node = curr_node.next
        nth_node = nth_node.next
    return nth_node


def getNthfromBeg(head: Node, n: int) -> Node:
    curr_node = head
    for i in range(n - 1):
        if curr_node is None:
            return None
        else:
            curr_node = curr_node.next
    return curr_node


if __name__ == "__main__":
    t = int(input())
    for cases in range(t):
        n, kth_node = map(int, input().strip().split())
        a = LinkedList()
        nodes_a = list(map(int, input().strip().split()))
        for x in nodes_a:
            a.append(x)
        check = [getNthfromBeg(a.head, kth_node), getNthfromEnd(a.head, kth_node)]
        new_head = swapkthnode(a.head, n, kth_node)
        new_check = [
            getNthfromEnd(new_head, kth_node),
            getNthfromBeg(new_head, kth_node),
        ]
        if check == new_check:
            print(1)
        else:
            print(0)
