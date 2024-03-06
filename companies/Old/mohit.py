def charsearch(xlist, sval):
    res = 0
    for i in xlist:
        if i[0] == sval:
            res += 1
    return res


def keyvalsearch(xdict, key):
    res = 0
    try:
        res = xdict[key]
    except KeyError:
        res = float("Nan")
    return res


def demorgan2(A, B, V):
    lhs = V.difference(A.intersection(B))
    rhs = set(V.difference(A)).intersection(set(V.difference(B)))
    return True if lhs == rhs else False


print(demorgan2(set([2, 3, 4]), set([3, 4, 5]), set([3, 4, 5])))
