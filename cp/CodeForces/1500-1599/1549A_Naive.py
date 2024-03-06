for _ in range(int(input())):
    p = int(input())
    a = 2
    b = a+1
    while a < p:
        flag = 0
        m = p % a
        for i in range(a+1, p):
            if p % b == m:
                print(a, b)
                flag = 1
                break
            else:
                b += 1
        if flag:
            break
        a += 1