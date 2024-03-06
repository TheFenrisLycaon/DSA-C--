"""
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time, y
ou could climb any number from a set of positive integers X?

For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
"""
from typing import *


def climbStairs(n: int) -> int:

    if n == 0 or n == 1:
        return 1

    ff = 1
    sf = 2
    for _ in range(3, n+1):
        nf = ff + sf
        ff, sf = sf, nf

    return sf


for i in range(int(input())):
    print(climbStairs(int(input())))
