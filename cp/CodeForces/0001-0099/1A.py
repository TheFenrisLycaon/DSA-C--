#!/usr/bin/env python

from math import *

s = input()
ss = s.split(" ")
n = int(ss[0])
m = int(ss[1])
a = int(ss[2])

if (n < m):
    t = n
    n = m
    m = t

sum = 1
top = 0
if (n > a):
    top = int(ceil(n * 1.0 / a))
    sum = top

if (m > a):
    sum += top * (int(ceil((m * 1.0 - a) / a)))

print(sum)

