import math


def b(x, n, p):
    res = (math.factorial(n)/(math.factorial(x)*math.factorial(n-x))) * \
        (p**x) * ((1-p)**(n-x))
    return res


if __name__=="__main__":
    nm = input().split()
    n = float(nm[0])
    m = float(nm[1])
    p = n/(n+m)
    tot = 0
    for i in range(3, 7):
        tot += b(i, 6, p)
    print("%.3f" % tot)
