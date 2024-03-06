#!/usr/bin/env python

s = input().split(" ")

n = int(s[0])
k = int(s[1])
l = int(s[2])
c = int(s[3])
d = int(s[4])
p = int(s[5])
nl = int(s[6])
np = int(s[7])

total_drink = k * l
total_toasts1 = total_drink / nl
total_toasts2 = c * d
total_toasts3 = p / np

print(min(total_toasts1, total_toasts2, total_toasts3) / n)
