#!/usr/bin/env python

a = input()
b = input()

c = int(a) + int(b)
aa = a.replace('0', '')
bb = b.replace('0', '')
cc = int(str(c).replace('0', ''))
dd = int(aa) + int(bb)

print("YES" if dd == cc else "NO")

