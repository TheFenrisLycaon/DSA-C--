for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    ans = (1*2)-k*(arr[0] | arr[1])
    for i in range(n):
        for j in range(i):
            ans = max((i+1)*(j+1)-k*(arr[i] | arr[j]), ans)
    print(ans)