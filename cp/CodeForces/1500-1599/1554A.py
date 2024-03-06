res = []
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    sol = 0
    for i in range(1,n):
        sol = max(sol, arr[i-1]*arr[i])
    res.append(sol)
 
for i in res:
    print(i)