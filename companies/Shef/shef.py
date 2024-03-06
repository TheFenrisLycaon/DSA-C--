from collections import Counter


def solve(n: int, num: list) -> list:
    parse = dict(sorted(Counter(num).items(), key=lambda a: (-a[1], a[0])))
    d = {n: [k for k in parse.keys() if parse[k] == n] for n in set(parse.values())}
    res = []
    for n in sorted(d.keys(), reverse=True):
        res += sorted(d[n], reverse=True)
    return res


print(solve(5, [1, 2, 2, 1, 6]))
