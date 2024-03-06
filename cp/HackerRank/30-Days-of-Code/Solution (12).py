a = []

for _ in range(6):
    tmp = [int(x) for x in str(input()).split(" ")]
    a.append(tmp)

maxm = -9 * 7

for i in range(6):
    for j in range(6):
        if j + 2 < 6 and i + 2 < 6:
            res = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1] + a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2]
            if res > maxm:
                maxm = res

print(maxm)
