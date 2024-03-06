def solve(n):
    def util(n, mapp):
        if n in mapp:
            return mapp[n]
        if n == 1:
            mapp[n] = 1
        elif n % 2 == 0:
            mapp[n] = 1 + util(n // 2, mapp)
        else:
            mapp[n] = 1 + util(3 * n + 1, mapp)

        return mapp[n]

    mapp = {}

    util(n, mapp)

    num, l = -1, 0

    for i in range(1, n):
        if i not in mapp:
            util(i, mapp)

        maxx = mapp[i]

        if l < maxx:
            l = maxx
            num = i

    return num


print(solve(5))
print(solve(10))
