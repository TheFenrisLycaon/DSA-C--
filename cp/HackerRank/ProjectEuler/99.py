import math

ans = {}
for i in range(int(input())):
    line = input()
    b, e = line.split()
    b = int(b)
    e = int(e)
    val = e*math.log10(b)
    ans[val] = line

i = int(input())
print(ans[sorted(ans)[i-1]])
