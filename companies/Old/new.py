from functools import reduce


def LCML(first, last):
    factors = list(range(first, last + 1))
    for i in range(0, len(factors)):
        if factors[i] != 1:
            n = first + i
            for j in range(2 * n, last + 1, n):
                factors[j - first] = factors[j - first] / factors[i]
    return reduce(lambda a, b: a * b, factors, 1)


for _ in range(int(input())):
    x, r = map(int, input().split())
    res = 0
    for i in range(1, r + 1):
        for j in range(i, r + 1):
            if LCML(i, j) == x:
                res += 1
    print(res)
