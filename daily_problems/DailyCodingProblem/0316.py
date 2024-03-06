"""
Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
"""
from typing import *


def jobs(f: Callable, n: int) -> None:
    """
    Call f after n milliseconds.
    """
    import time

    time.sleep(n / 1000)
    f()


for i in range(int(input())):
    print(jobs(lambda: print(i), int(input())))
