"""
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
"""
from typing import *


def check(arr: List, target: int) -> bool:
    """Return whether any two numbers from the list add up to target"""
    return (
        True
        if any(
            target - val in arr[:idx] + arr[idx + 1 :] for val, idx in enumerate(arr)
        )
        else False
    )


for i in range(int(input())):
    print(check(list(map(int, input().split())), int(input())))
