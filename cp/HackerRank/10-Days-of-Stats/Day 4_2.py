import math


def b(x, n, p):
    res = (math.factorial(n)/(math.factorial(x)*math.factorial(n-x))) * \
        (p**x) * ((1-p)**(n-x))
    return res


if __name__ == "__main__":
    pn = input().split()
    p = float(pn[0])/100
    n = int(pn[1])
    tot = 0
    for i in range(0, 3):
        tot += b(i, n, p)

    print("%.3f" % tot)
    tot = 0
    for i in range(2, n):
        tot += b(i, n, p)

    print("%.3f" % tot)
