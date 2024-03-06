#!/usr/bin/env python
n = int(input())
print("%.8f" % (sum([x for x in map(int, input().split(' '))]) / float(n)))