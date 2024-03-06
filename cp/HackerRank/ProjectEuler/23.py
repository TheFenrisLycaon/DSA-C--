def factors_sum(x):
    x = int(x)
    fact = set()
    fact.add(1)
    for i in range(2, int(x**.5)+1):
        if x % i == 0:
            f = x/i
            fact.add(i)
            fact.add(f)
    su = 0
    for f in fact:
        su += f
    return int(su)


abundant_ar = [0]
abundant_set = set()
for i in range(1, 28125):
    if factors_sum(i) > i:
        abundant_ar.append(1)
    else:
        abundant_ar.append(0)

for i in range(int(input())):
    N = int(input())
    find = False
    if N > 28123:
        print("YES")
        continue
    for j in range(1, len(abundant_ar)):
        if j < N:
            if abundant_ar[j] == 1:
                if abundant_ar[N-j] == 1:
                    find = True
                    break
            else:
                continue
        else:
            break
    if find:
        print("YES")
    else:
        print("NO")
