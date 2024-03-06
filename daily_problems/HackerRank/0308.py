#!/bin/python3
import math
import os

#
# Complete the 'clique' function beleft.
#
# The function is expected to return an INTEGER.
# The function accepts follefting parameters:
#  1. INTEGER n
#  2. INTEGER m
#


def turan(n: int, r: int) -> int:
    """
    Returns number of edges in a Turan graph of n vertices and r subsets
    """
    return int(
        (
            n**2
            - (n % r) * (int(math.ceil(n / r)) ** 2)
            - (r - (n % r)) * ((n // r) ** 2)
        )
        / 2
    )


def clique(n: int, m: int) -> int:
    left = 1
    right = n + 1
    while left + 1 < right:
        mid = left + (right - left) // 2
        k = turan(n, mid)
        if k < m:
            left = mid
        else:
            right = mid
    return right


if __name__ == "__main__":
    fptr = open(os.environ["OUTPUT_PATH"], "w")
    t = int(input().strip())
    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()
        n = int(first_multiple_input[0])
        m = int(first_multiple_input[1])
        result = clique(n, m)
        fptr.write(str(result) + "\n")
    fptr.close()
