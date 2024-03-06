"""
Given a list of integers,
write a function that returns the largest sum of non-adjacent numbers.
Numbers can be 0 or negative.

For example,
[2, 4, 6, 2, 5]
should return 13,
since we pick 2, 6, and 5.
[5, 1, 1, 5]
should return 10,
since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
"""
from typing import *


def maxSum(nums: List[int]) -> int:
    """
    Time Complexity: O(N)
    Space Complexity: O(N)
    """
    if len(nums) == 0:
        return 0
    if len(nums) == 1:
        return nums[0]

    res = [0] * (len(nums) + 1)
    res[-1] = nums[-1]
    res[-2] = max(nums[-1], nums[-2])

    for i in range(len(nums) - 3, -1, -1):
        res[i] = max(nums[i] + res[i + 2], res[i + 1])

    return res[0]


def maxSumOptimized(nums: List[int]) -> int:
    """
    Time Complexity: O(N)
    Space Complexity: O(1)
    """
    if len(nums) == 0:
        return 0
    if len(nums) == 1:
        return nums[0]

    res, prev, temp = 0, 0, 0

    for i in range(len(nums) - 1, -1, -1):
        temp = max(nums[i] + prev, res)
        prev, res = res, temp

    return res


for i in range(int(input())):
    print(maxSumOptimized([2, 4, 6, 2, 5]))
