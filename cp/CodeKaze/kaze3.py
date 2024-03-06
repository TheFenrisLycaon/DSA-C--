from typing import *


def countPairs(a: List[int], n: int, k: int) -> int:
    res = 0
    for i in range(n):
        res += len([x for x in a[i + 1 :] if x + a[i] > k])
    return res


def findPairs(arr, n, x):
    l = 0
    r = n - 1
    result = 0
    while l < r:
        if arr[l] + arr[r] > x:
            result += r - l
            l += 1
        else:
            r -= 1
    return result


for i in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    print(countPairs(a, n, k))
