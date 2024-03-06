def g(n,p):
    res = ((1-p)**(n-1)) * p
    return res

if __name__=="__main__":
    tot, n, p = 0, 5, 1/3
    for i in range(1,6):
        tot += g(i,p)
        print(tot)
    print("%.3f"%tot)