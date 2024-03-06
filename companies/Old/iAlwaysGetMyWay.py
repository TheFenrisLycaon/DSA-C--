from functools import lru_cache
import sys

sys.setrecursionlimit(15000)


@lru_cache
def countTotalWaysRecursive(poolSize, bucketSize):
    if poolSize < 0:
        return 0
    if poolSize == 0:
        return 1
    ways = 0
    for i in range(1, bucketSize + 1):
        ways += countTotalWays(poolSize - i, bucketSize)
    return ways


def countTotalWays(poolSize, bucketSize):
    tempVar = 0
    ways = [1]

    for i in range(1, poolSize + 1):
        s = i - bucketSize - 1
        e = i - 1
        if s >= 0:
            tempVar -= ways[s]
        tempVar += ways[e]
        ways.append(tempVar)

    return ways[poolSize]


for _ in range(int(input())):
    poolCap, bucketCap = map(int, input().split())
    print(countTotalWays(poolCap, bucketCap) % 1000000007)
