#!/usr/bin/env python

from sys import *

s = stdin.readline()

i = 0
j = len(s)
lvl = 0
while i < j:
    c = s[i]
    if c == '<':
        if s[i + 1] == '/':
            i += 1
            k = i + 1
            while s[k] != '>':
                k += 1
            tag = s[i + 1: k]
            lvl -= 2
            print(" " * lvl + "</" + tag + ">")
            i = k
        else:
            k = i + 1
            while s[k] != '>':
                k += 1
            tag = s[i + 1: k]
            print(" " * lvl + "<" + tag + ">")
            lvl += 2
            i = k
    i += 1
    






