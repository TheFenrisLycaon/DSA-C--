from bisect import bisect_right
from typing import *


def greaterElement(arr, n):
    sortedArr = sorted(arr[:])
    res = []
    for e in arr:
        idx = bisect_right(sortedArr, e)
        res.append(-10000000 if idx == n else sortedArr[idx])
    return res


for _ in range(0, int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    res = greaterElement(arr, n)
    res = ""
    for i in res:
        if i == -10000000:
            res += "_ "
        else:
            res += str(i) + " "
    print(res)
