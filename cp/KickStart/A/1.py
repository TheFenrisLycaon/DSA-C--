import random


def count(w1, wnew):
    return sum(c1 == c2 for c1, c2 in zip(w1, wnew))


def best_shuffle(w):
    wnew = list(w)
    n = len(w)
    rangelists = (list(range(n)), list(range(n)))
    for r in rangelists:
        random.shuffle(r)
    rangei, rangej = rangelists
    for i in rangei:
        for j in rangej:
            if i != j and wnew[j] != wnew[i] and w[i] != wnew[j] and w[j] != wnew[i]:
                wnew[j], wnew[i] = wnew[i], wnew[j]
                break
    wnew = "".join(wnew)
    return wnew, count(w, wnew)


for _ in range(int(input())):
    print(f"Case #{_}: {best_shuffle(input().split())}")
