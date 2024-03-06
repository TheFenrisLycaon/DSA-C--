def primogen(n):
    m = n + 1
    nums = [True] * m
    for i in range(2, int(n**0.5 + 1)):
        if nums[i]:
            for j in range(i * i, m, i):
                nums[j] = False
    primes = []
    for i in range(2, m):
        if nums[i]:
            primes.append(i)
    return set(primes)


def solve(p1, p2):
    l = list(set(x for x in range(p1, p2)).difference(primogen(p2)))
    for i in range(len(l)):
        for j in range(i + 1, len(l)):
            if (l[i] * l[j]) / ((l[i] - l[j]) ** 2) >= f:
                return [l[i], l[j]]
    return None


if __name__ == "__main__":
    f, p1, p2 = map(int, input().split())
    ans = solve(p1, p2)
    if ans:
        print(ans[0], ans[1])
    else:
        print(None)
