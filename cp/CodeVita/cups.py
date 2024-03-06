if __name__ == "__main__":
    cups = int(input())
    cap = list(map(int, input().split()))
    jug = int(input())
    res = {cup: 0 for cup in cap}
    if sum(cap) < jug:
        for cup in res.keys():
            res[cup] = 1
            jug -= cup
    while jug != 0:
        for cup in res.keys():
            if jug > cup:
                jug -= cup
                res[cup] += 1
    print(res, jug)
