from math import *

n = int(input()) * 2

k = int(round(sqrt(n)))

found = False

for i in range(1, k):
    r = n - i * i - i
    x = int(floor(sqrt(r)))
    if x * (x + 1) == r:
        found = True
        break

print("YES" if found else "NO")
