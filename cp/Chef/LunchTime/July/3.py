for _ in range(int(input())):
    n, d, h = map(int, input().split())
    arr = list(map(int, input().split()))
    s = 0
    for i in range(n):
        if arr[i] != 0:
            s += arr[i]
        else:
            s -= d
            if s < 0:
                s = 0
        if s <= h:
            flag = "NO"
        else:
            flag = "YES"
            break
    print(flag)