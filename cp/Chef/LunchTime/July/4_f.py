def getMin(a, b, b1, b2, n):
    i=0
    mod1 = (a[i]+b[b1]) % n
    mod2 = (a[i] + b[b2]) % n
    while i < n-1 and mod1 == mod2:
        b1 = (b1+1) % n
        b2 = (b2+1) % n
        i += 1
        mod1 = (a[i]+b[b1]) % n
        mod2 = (a[i] + b[b2]) % n
    if mod1 < mod2:
        return b1
    else:
        return b2


def getC(a, b, n):
    return [(a[i]+b[i]) % n for i in range(n)]


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    minT = 4*n+1
    for bi in b:
        minT = min((a[0]+bi) % n, minT)
    ind = []
    i = 0
    for bi in b:
        if (a[0]+bi) % n == minT:
            ind.append(i)
        i += 1

    if len(ind) == 1:
        b = b[:ind[0]] + b[ind[0]:]
        c = getC(a, b, n)
    else:
        index = getMin(a, b, ind[0], ind[1], n)
        b = b[index:] + b[:index]
        c = getC(a, b, n)

    print(c)
