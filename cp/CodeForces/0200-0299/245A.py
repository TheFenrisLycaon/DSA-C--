#!/usr/bin/env python

ax = asum = 0
bx = bsum = 0

for i in range(int(input())):
    t, x, y = list(map(int, input().split()))
    if t == 1:
        ax += x
        asum += 10
    else:
        bx += x
        bsum += 10

print("LIVE" if ax + ax >= asum else "DEAD")
print("LIVE" if bx + bx >= bsum else "DEAD")




