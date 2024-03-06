res = []
for _ in range(int(input())):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    c = 0
    for i in range(n):
        if a[i] > a[0]:
            c += 1
    res.append(c)
for i in res:
    print(i)
