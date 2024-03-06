from math import factorial as f
def p(n, m): return f(n+m) // (f(n) * f(m))


for _ in range(int(input())):
    print(p(*map(int, input().split())) % 1000000007)
