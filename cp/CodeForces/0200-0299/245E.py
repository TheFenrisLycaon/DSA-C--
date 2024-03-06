#!/usr/bin/env python

p, m = 0, 0
for _ in input():
    if _ == '+':
        p += 1
        if m:
            m -= 1
    else:
        m += 1
        if p:
            p -= 1
print(p + m)
    

