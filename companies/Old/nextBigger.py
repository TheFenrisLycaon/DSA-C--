import itertools


def nextBigger(n):
    try:
        return min(
            [
                x
                for x in map(
                    int,
                    [
                        "".join(permutation)
                        for permutation in itertools.permutations(str(n))
                    ],
                )
                if x > n
            ]
        )
    except:
        return -1


# def nextBigger(n):
#     ns = str(n)
#     if len(ns) > 1:
#         ks = int(ns[:-2]+ns[-1]+ns[-2])
#         if ks > n:
#             return ks
#     return -1


print(nextBigger(12))
print(nextBigger(513))
print(nextBigger(2017))
print(nextBigger(531))
