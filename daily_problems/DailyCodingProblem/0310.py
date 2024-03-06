"""
Given an array of integers, find the first missing positive integer in linear time and constant space.
In other words, find the lowest positive integer that does not exist in the array.
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
"""
from typing import *


def foo(arr: List[int], n: int) -> int:
    return n * (n + 1) // 2 - sum([x for x in arr if x > 0])


for i in range(int(input())):
    print(foo(list(map(int, input().split())), int(input())))
