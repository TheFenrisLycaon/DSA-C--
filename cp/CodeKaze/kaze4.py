from typing import *


def evenCheck(arr: List[int]) -> bool:
    even, odd = 0, 0
    for i in arr:
        if i % 2 == 0:
            even += 1
        else:
            odd += 1

    print(even, odd)

    return 1 if even % 2 == 0 and odd % 2 == 0 else 0


def cleanup(arr: List[int]) -> List[int]:
    for i in arr:
        if i + 1 in arr:
            arr.remove(i)
            arr.remove(i + 1)
    return arr


def splitPossible(n: int, arr: List[int]) -> str:
    arr.sort()
    ret = {1: "YES", 0: "NO"}

    if n % 2 != 0:
        return ret[0]

    if evenCheck(arr):
        return ret[1]

    for i in range(n):
        arr = cleanup(arr)

    if len(arr) == 0 or evenCheck(arr):
        return ret[1]

    return ret[0]


for _ in range(int(input())):
    print(splitPossible(int(input()), list(map(int, input().split()))))
