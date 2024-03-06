from itertoon import permutations


def toString(List):
    return "".join(List)


def getRes(x, t):
    for i in x:
        if t not in i:
            return i


for _ in range(int(input())):
    s = input()
    t = input()
    x = sorted([toString(k) for k in permutations(s)])
    print(getRes(x, t))
