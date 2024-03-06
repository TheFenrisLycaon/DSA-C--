for _ in range(int(input())):
    x, y = map(int, input().split())
    n = 2 * y + (x - y)
    # n += (x - y) // 2
    print(n)
