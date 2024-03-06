#!/usr/bin/env python

from sys import stdin

s = stdin.readline()
ans = 0
a = 0
for i in s:
    if i.islower():
        a += 1
    elif i.isupper() and a > 0:
        a -= 1
        ans += 1
print(ans)
