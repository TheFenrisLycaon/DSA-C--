for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    clist = []
    for l in range(n):
        clist.append([(a[i]+b[i])%n for i in range(n)])
        b = b[1:] + [b[0]]
    for i in min(clist):
        print(i, end=' ')
