def gp(n):
    num = set()
    prime = {}
    su = 0
    for i in range(2, n+1):
        num.add(i)
    l = len(num)
    while(l > 0):
        p = num.pop()
        su += p
        prime[p] = su
        i = 2
        while(i*p <= n+1):
            if i*p in num:
                num.remove(i*p)
            i += 1
        l = len(num)
    return prime


res = 0
prime = gp(1000000)
res = 0
for n in range(2, int(input())+1):
    cp = True
    if n in prime:
        n_str = str(n)
        for p in range(len(n_str)):
            rot = int(n_str[p:]+n_str[:p])
            if not rot in prime:
                cp = False
                break
        if cp:
            res += n
print(res)
