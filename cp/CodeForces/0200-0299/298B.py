#!/usr/bin/env python

n, sx, sy, ex, ey = list(map(int, input().split()))

cnt = 0
flag = False
for i in input().strip():
    if ex > sx:
        if i == 'E':
            sx += 1
    elif ex < sx:
        if i == 'W':
            sx -= 1
    if ey > sy:
        if i == 'N':
            sy += 1
    elif ey < sy:
        if i == 'S':
            sy -= 1
    cnt += 1
    if sx == ex and sy == ey:
        print(cnt)
        flag = True
        break    
    
if not flag:
    print(-1)

