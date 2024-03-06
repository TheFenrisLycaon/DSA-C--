import math

findn = False
for a0 in range(int(input())):
    findn = False
    n = int(input().strip())
    for j in range(n - 1, 101100, -1):
        strn = str(j)
        if strn[0] == strn[5] and strn[1] == strn[4] and strn[2] == strn[3]:
            if not findn:
                for i in range(int(math.sqrt(j)), 101, -1):
                    if j % i == 0 and (i >= 100 and i <= 999) and (j // i >= 100 and j // i <= 999):
                        print(j)

                        findn = True
                        break
            else:
                break
