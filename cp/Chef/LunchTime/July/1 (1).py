for _ in range(int(input())):
    spells = sorted(list(map(int, input().split())))
    print(spells[-1]+spells[-2])
