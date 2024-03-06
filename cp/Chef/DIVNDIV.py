def getK(x, y, z):
    if z % y == 0 or y % z == 0:
        return -1
    x += 1
    while True:
        if x % y == 0 and x % z != 0:
            return x
        x += 1


for _ in range(int(input())):
    x, y, z = map(int, input().split())
    print(getK(x, y, z))
