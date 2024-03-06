#!/usr/bin/env python
# http://acm.zhihua-lai.com

from sys import stdin

n = int(stdin.readline())

def convert1(row, col):
    s = ""
    while col:
        m = (col - 1) % 26
        col = (col - 1) / 26
        s = chr(65 + m) + s
    return s + str(row)

def convert2(s):
    r = 0
    for i in s:
        r = r * 26 + ord(i) - 64
    return r

# check which type
def chk(s):
    if s[0] == 'R' and s[1].isdigit():
        i = 2
        while i < len(s):
            if s[i] == 'C':
                return True
            i += 1
    return False

# extract numbers
def ex(s):
    rr = []
    r = 0
    i = 0
    while i < len(s):
        if not s[i].isdigit():
            i += 1
        else:
            break

    while i < len(s):
        if s[i].isdigit():
            r = r * 10 + ord(s[i]) - 48
            i += 1
        else:
            break
    rr.append(r)
    
    if i == len(s):
        return rr

    while i < len(s):
        if not s[i].isdigit():
            i += 1
        else:
            break    
    r = 0
    while i < len(s):
        if s[i].isdigit():
            r = r * 10 + ord(s[i]) - 48
            i += 1
        else:
            break
    rr.append(r)
    return rr
        
for i in range(n):
    s = stdin.readline()
    if chk(s):
        num = ex(s)
        print(convert1(num[0], num[1]))        
    else:
        i = 0
        while i < len(s):
            if s[i].isdigit():
                break
            else:
                i += 1
        print('R' + s[i:].strip() + 'C' + str(convert2(s[:i]))) 
