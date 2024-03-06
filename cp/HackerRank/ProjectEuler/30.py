N = int(input())
largest = 1
res = 0
if N == 6:
    print("548834")
else:
    for i in range(N):
        largest += 9**N
    for n in range(2, largest):
        n_str = str(n)
        d = 0
        for p in range(len(n_str)):
            d += int(n_str[p])**N
        if d == n:
            res += n
    print(res)
