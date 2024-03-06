def goodness(s):
    res = 0
    n = len(s)
    for i in range(1, n//2+1):
        # print(s[i])
        # print(s[n-i])
        if s[i] != s[n-i]:
            res += 1
    return res

def change(l,expect ):
    ptr = 1
    res = 0
    val = goodness(l)
    while val != expect and ptr <= len(l)//2:
        # print(ptr)
        if l[-ptr] != l[ptr]:
            l[-ptr] = l[ptr]
            res += 1
            val = goodness(str(l))
            ptr+=1
        else:
            ptr += 1
    return res

for _ in range(int(input())):
    x = list(map(int,input().split()))
    l = [' '] + list(str(input( )))
    res = ''
    res += f'Case #{_+1}: ' + str(change(l, x[1]))

print(res)
