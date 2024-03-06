res = []


def summ(x):
    my_sum = 0
    i = 0
    while i <= x:
        my_sum = my_sum + i
        i += 1
    return my_sum


for _ in range(int(input())):
    g = int(input())
    for i in range(1, g):
        k = summ(i)
        if k < g:
            continue
        elif k == g:
            r = i
            break   
        else:
            r = i-1
            break

    for i in range(r,1,-1):
        g = g-i
        # print(g)

    res.append(f"Case #{_+1}: {g+1}")


for i in res:
    print(i)