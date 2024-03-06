

from collections import defaultdict
def lambda_fnc_input(): return [*map(int, input().split())]


def intevels(r, c, matrix):
    rows, cols = defaultdict(list), defaultdict(list)
    for i in range(r):
        start = -1
        for j in range(c):
            if matrix[i][j]:
                if start == -1:
                    start = j
            else:
                if start != -1:
                    rows[i].append((start, j))
                    start = -1
        if start != -1:
            rows[i].append((start, c))

    for i in range(c):
        start = -1
        for j in range(r):
            if matrix[j][i]:
                if start == -1:
                    start = j
            else:
                if start != -1:
                    cols[i].append((start, j))
                    start = -1
        if start != -1:
            cols[i].append((start, r))

    return rows, cols


def connections(rows, cols):
    for i, row in rows.items():
        for x in row:
            if x[1] - x[0] < 2:
                continue
            for j in range(*x):
                vertex = next(
                    vertex for vertex in cols[j] if vertex[0] <= i < vertex[1])
                if vertex[1] - vertex[0] < 2:
                    continue
                yield i-vertex[0]+1, x[1]-j, vertex[1]-i, j-x[0]+1


def score(sc):
    sc += sc[0],
    return sum(
        max(0, min(a-1, b//2-1)) + max(0, min(b-1, a//2-1))
        for a, b in zip(sc, sc[1:])
    )


def solutions(r, c, matrix):
    rows, cols = intevels(r, c, matrix)
    return sum(map(score, connections(rows, cols)))


for test_case in range(int(input())):
    r, c = lambda_fnc_input()
    matrix = [lambda_fnc_input() for _ in range(r)]
    get_res = solutions(r, c, matrix)
    print('Case #{0}: {1}'.format(test_case+1, get_res))
