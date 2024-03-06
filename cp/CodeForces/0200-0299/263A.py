#!/usr/bin/env python

for i in range(1, 6):
    s = list(map(int, input().split()))
    for k in range(1, 6):
        if s[k - 1] == 1:
            print(abs(i - 3) + abs(k - 3))
            break
