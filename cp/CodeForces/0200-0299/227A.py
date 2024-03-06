#!/usr/bin/env python

def read():
    return list(map(int, input().split(' ')))

x1, y1 = read()
x2, y2 = read()
x3, y3 = read()

k = (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1)
print(['TOWARDS','RIGHT','LEFT'][cmp(k, 0)])
