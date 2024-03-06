s = input()

i = 0
t = len(s)

def getsum(k):
    u = 0
    while k > 0:
        u += k % 10
        k /= 10
    return u

if t == 1 and int(s) < 10:
    print(0)
else:
    ss = 0
    while i < t:
        ss += int(s[i])
        i += 1

    ans = 1
    while ss >= 10:
        ans += 1
        ss = getsum(ss)    

    print(ans)