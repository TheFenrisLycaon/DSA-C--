"""
A unival tree (which stands for "universal val") is a tree where all nodes under it have the same val.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
"""
from typing import *


class Node:
    def __init__(self, val: int, left=None, right=None) -> None:
        self.val: int = val
        self.left: Node = left
        self.right: Node = right


def univialCheck(root: Node) -> bool:
    def util(root: Node, val: int) -> bool:
        if root is None:
            return True
        if root.val == val:
            return util(root.left, val) and util(root.right, val)
        return False

    return util(root, root.val)


def univialCount(root: Node) -> int:
    if root is None:
        return 0
    left = univialCount(root.left)
    right = univialCount(root.right)
    return 1 + left + right if univialCheck(root) else left + right


def univialCountOptimized(root: Node) -> int:
    def helper(root: Node) -> Tuple[int, bool]:
        if root is None:
            return 0, True

        leftCount, univCheckLeft = helper(root.left)
        rightCount, univCheckRight = helper(root.right)

        totalCount = leftCount + rightCount

        if univCheckLeft and univCheckRight:
            if root.left is not None and root.val != root.left.val:
                return totalCount, False

            if root.right is not None and root.val != root.right.val:
                return totalCount, False

            return totalCount + 1, True

        return totalCount, False

    count, _ = helper(root)
    return count


root = Node(0, Node(1), Node(0, Node(0), Node(1, Node(1), Node(1))))
for i in range(int(input())):
    print(univialCountOptimized(root))
