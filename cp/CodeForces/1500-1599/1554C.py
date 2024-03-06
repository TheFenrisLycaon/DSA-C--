for _ in range(int(input())):
    n, m = map(int, input().split())
    t = []
    for i in range(m+1):
        k = n ^ i
        if k > 0:
            t.append(k)
    t.sort()
    count = 0
    sol = 0
    for i in t[1:]:
        m = t[count] + 1
        if i != m:
            sol = m
            break
        else:
            count += 1
    print(sol)
