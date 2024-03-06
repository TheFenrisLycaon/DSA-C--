n = int(input());

aa = input();
bb = input();

laa = len(aa)
lbb = len(bb)

def gcd(x, y):
    if (y == 0):
        return x
    else:
        return gcd(y, x % y)

def lcm(x, y):
    return x / gcd(x, y) * y

m = lcm(laa, lbb)
  
def work(mm):
    i = 0
    a = 0
    b = 0
    while i < mm:
        j = i % laa
        k = i % lbb
        if (aa[j] == bb[k]):
            pass
        elif (aa[j] == 'R'):
            if (bb[k] == 'P'):
                a += 1 
            else:
                b += 1
        elif (aa[j] == 'P'):
            if (bb[k] == 'R'):
                b += 1
            else:
                a += 1
        else: # S
            if (bb[k] == 'R'):
                a += 1
            else:
                b += 1
        i += 1
    return [a, b]

la = 0
lb = 0

mm = work(m)
a = mm[0]
b = mm[1]

aaa = 0
bbb = 0
k = n % m
if (k == 0):
    la = a * n / m
    lb = b * n / m
elif (n > m):
    mm = work(k)
    aaa = mm[0]
    bbb = mm[1]
    la = a * (n / m) + aaa
    lb = b * (n / m) + bbb  
else:
    mm = work(n)
    aaa = mm[0]
    bbb = mm[1]
    la = aaa
    lb = bbb
    
print(la, " ", lb)