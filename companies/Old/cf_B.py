for _ in range(int(input())):
    comp, cab = map(int, input().split())
    # print(comp, cab)
    i = 0
    usedCab = 0
    while comp > 1:
        if usedCab < cab:
            usedCab = usedCab * 2 + (usedCab == 0)
        if usedCab > cab:
            usedCab = cab
        comp -= usedCab
        i += 1
    print(i)
