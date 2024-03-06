#!/usr/bin/env python
# www.zhihua-lai.com/acm
# http://www.codeforces.com/problemset/problem/245/B

from sys import stdin

s = stdin.readline().strip()

j = 3
if s[0] == 'h':
    j = 4

i = j
k = 0
while i < len(s):
    if k > 0 and s[i] == 'r' and s[i + 1] == 'u':
        break
    i += 1
    k = 1

if i + 2 == len(s):
    print(s[:j] + "://" + s[j:i] + ".ru")
else:
    print(s[:j] + "://" + s[j:i] + ".ru/" + s[i+2:])
