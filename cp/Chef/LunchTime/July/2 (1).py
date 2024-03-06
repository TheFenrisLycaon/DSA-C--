# 4
# 4 2 6
# 1 3 0 2
# 2 1 100
# 1 100
# 4 2 3
# 1 2 0 2
# 3 7 10
# 5 3 9

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
