#!/usr/bin/env python
# http://acm.zhihua-lai.com

n = int(input())

a = dict()
ans = 1
xx = 1

for x in range(n):
    h, s = list(map(int, input().strip().split(" ")))
    t = h * 60 + s
    if t in a:
        ans += 1
        if ans > xx: xx = ans
    else:
        a[t] = True
        ans = 1

print(xx)
