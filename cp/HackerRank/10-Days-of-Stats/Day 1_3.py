import math
n = int(input())
x = [int(i) for i in input().split()]
u = sum(x)/n
var = 0
for i in range(n):
    var += math.pow(x[i]-u,2)/n
stdder = math.sqrt(var)
print(round(stdder,1))
