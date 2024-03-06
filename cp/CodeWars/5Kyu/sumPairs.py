def sum_pairs(ints, s):
    cacheTable = set()
    for i in ints:
        j = s - i
        if j in cacheTable:
            return [j, i]
        cacheTable.add(i)