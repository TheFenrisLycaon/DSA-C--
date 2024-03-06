s = input("").split(" ")

n = int(s[0])
m = int(s[1])

if n == 0:
    if m == 0:
        print(0, " ", 0)
    else:
        print("Impossible")
elif m <= 1:
    print(n, " ", n)
elif (n == m):
    print(n, " ", 2 * n - 1)
elif (n > m):
    print(n, " ", n - 1 + m)
else:
    print(m, " ", n + m - 1)