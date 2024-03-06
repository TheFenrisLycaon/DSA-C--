#!/usr/bin/env python
n, m = list(map(int, input().split()))
k = min(n, m)
print(k + 1)
for x in range(k + 1):
    print(x, k - x)
