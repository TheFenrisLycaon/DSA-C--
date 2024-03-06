"""
Given the root to a binary tree,
implement serialize(root),
which serializes the tree into a string,
and deserialize(s),
which deserializes the string back into the tree.
"""
from typing import *


class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def serialize(root):
    """Encodes a tree to a single string.

    :type root: Node
    :rtype: str
    """

    def helper(node):
        if node:
            nodeValues.append(node.val)
            helper(node.left)
            helper(node.right)
        else:
            nodeValues.append("#")

    nodeValues = []
    helper(root)
    return " ".join(nodeValues)

def deserialize(data):
    """Decodes your encoded data to tree.

    :type data: str
    :rtype: Node
    """

    def helper():
        val = next(nodeValues)
        if val == "#":
            return None
        node = Node(val)
        node.left = helper()
        node.right = helper()
        return node

    nodeValues = iter(data.split())
    return helper()


node = Node("root", Node("left", Node("left.left")), Node("right"))
assert deserialize(serialize(node)).left.left.val == 'left.left'
