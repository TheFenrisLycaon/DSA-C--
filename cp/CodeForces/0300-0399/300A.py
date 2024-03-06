#!/usr/bin/env python

n = int(input())
a = list(map(int, input().split()))

s1 = [i for i in a if i < 0]
s2 = [i for i in a if i > 0]
s3 = [i for i in a if i == 0]

def pr(x):
    print(len(x), " ".join(map(str, x)))

if len(s2) == 0:
    s2.append(s1.pop())
    s2.append(s1.pop())

if len(s1) % 2 == 0:
    s3.append(s1.pop())

pr(s1)
pr(s2)
pr(s3)
    
