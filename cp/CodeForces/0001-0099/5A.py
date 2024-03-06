#!/usr/bin/env python

from sys import stdin
cnt = 0
p = 0

while True:
    s = stdin.readline().strip()
    if len(s) <= 1: break
    if s[0] == '+':
        p += 1
    elif s[0] == '-':
        p -= 1
    else:
        x = s.find(':')
        cnt += len(s[x+1:]) * p
print(cnt)
