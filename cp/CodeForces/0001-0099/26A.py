#!/usr/bin/env python

n = int(input())

def chk(n):
    i = 2
    j = 0
    k = 1
    while n > 1:
        u = n % i == 0
        if u:
            while n > 1:
                n /= i # divisor extraction
                if n % i > 0:
                    break
        if i == 3:
            k = 2 # skip even numbers
        i += k
        if u:
            j += 1
            if j > 2: # can't be almost prime
                return False
    return j == 2
        
s = 0
for i in range(6, n + 1):
    if chk(i):
        s += 1

print(s)

