#!/usr/bin/env python

from sys import stdin

fun = lambda: list(map(int, stdin.readline().split(" ")))

n, m = fun()
a = fun()
b = fun()

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if n > m:
    if a[0] * b[0] > 0:
        print("Infinity")
    else:
        print("-Infinity")
elif n == m:
    t = gcd(a[0], b[0])
    print("%d/%d" % (a[0] / t, b[0] / t))
else:
    print("0/1")
