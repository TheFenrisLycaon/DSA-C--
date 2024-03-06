from math import log10 as l
from math import ceil as c


def fib_term(N):
    Phi = float(1.618033988)
    n = (N-1+0.5*l(5))/l(Phi)
    return c(n)


for i in range(int(input())):
    t = fib_term(int(input()))
    print(t)
