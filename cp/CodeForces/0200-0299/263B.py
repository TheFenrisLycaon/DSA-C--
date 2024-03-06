#!/usr/bin/env python

n, k = list(map(int, input().split()))
a = list(map(int, input().split()))

if k > n:
    print(-1)
else:
    a.sort()
    print(a[n - k], 0)
