def median(x, n):
    res = []
    if n % 2 == 0:
        x1 = [x[i] for i in range(n//2)]
        x2 = [x[i] for i in range(n//2, n)]
        median = (x1[-1]+x2[0])/2
    else:
        x1 = [x[i] for i in range(n//2)]
        x2 = [x[i] for i in range((n//2)+1, n)]
        median = x[(n//2)]
    res.append(x1)
    res.append(x2)
    res.append(round(median, 1))
    return res


def quartile(x, n):
    res = []
    k = median(x, n)
    Q1 = median(k[0], len(k[0]))
    Q2 = median(k[1], len(k[1]))
    res.append(Q1[2])
    res.append(k[2])
    res.append(Q2[2])
    return res


def printm(x):
    y = int(x)
    if x == y:
        print(y)
    else:
        print(x)

if __name__=='__main__':
    n = int(input())
    x = [int(i) for i in input().split()]

    x.sort()


    q = quartile(x, n)
    printm(q[0])
    printm(q[1])
    printm(q[2])
