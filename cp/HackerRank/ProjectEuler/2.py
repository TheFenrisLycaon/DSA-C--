for a0 in range(int(input())):
    p, c, s = 0, 2, 0
    while c <= int(input()):
        s += c
        p, c = c, p + 4 * c
    print(s)
