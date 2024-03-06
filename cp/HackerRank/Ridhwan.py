mn = 1000


def parity(even, odd, v, i):
    global mn
    if i == len(v) or len(even) == 0 or len(odd) == 0:
        count = 0
        for j in range(len(v) - 1):
            if v[j] % 2 != v[j + 1] % 2:
                count += 1
        if count < mn:
            mn = count
        return
    if v[i] != -1:
        parity(even, odd, v, i + 1)
    else:
        if len(even) != 0:
            x = even[len(even) - 1]
            even.remove(even[len(even) - 1])
            v[i] = x
            parity(even, odd, v, i + 1)
            even.append(x)
        if len(odd) != 0:
            x = odd[len(odd) - 1]
            odd.remove(odd[len(odd) - 1])
            v[i] = x
            parity(even, odd, v, i + 1)
            odd.append(x)


def mnDiffParity(v, n):
    global mn
    even = []
    odd = []
    m = {i: 0 for i in range(100)}
    for i in range(1, n + 1):
        m[i] = 1
    for i in range(len(v)):
        if v[i] != -1:
            m.pop(v[i])
    for key in m.keys():
        if key % 2 == 0:
            even.append(key)
        else:
            odd.append(key)
    parity(even, odd, v, 0)
    print(mn + 4)


if __name__ == "__main__":
    n = 5
    # v = [4, 10, 10, 6, 2]
    v = [6, 5, 9, 7, 3]
    # v = [2, 1, 4, -1,-1, 6, -1, 8]
    mnDiffParity(v, n)
