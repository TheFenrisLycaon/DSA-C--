#!/usr/bin/env python

s = input()
t = input()

j = 0
for i in t:
    if i == s[j]:
        j += 1

print(j + 1)
