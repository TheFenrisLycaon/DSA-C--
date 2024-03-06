"""
Given a stream of elements too large to store in memory,
pick a random element from the stream with uniform probability.
"""
from typing import *
from random import randint


def pickRandom(stream: List[int]) -> int:
    res = None
    for i, e in enumerate(stream):
        if i == 0:
            res = e
        elif randint(1, i + 1) == 1:
            res = e
    return res


for i in range(int(input())):
    print(pickRandom(list(map(int, input().split()))))
