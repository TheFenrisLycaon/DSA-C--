def solve(A, B):
    X = [0] * (A + 1)
    Y = [0] * (A + 1)
    for query in B:
        if query[0] == 1:
            for i in range(query[1], query[2] + 1):
                X[i] = not (X[i])
        elif query[0] == 2:
            for i in range(1, A):
                Y[i] = Y[i] + X[i] * query[1]
        elif query[0] == 3:
            print(Y[query[1]])


print(solve(5, [[1, 2, 3], [2, 5, 0], [1, 1, 4], [3, 4, 0], [2, 6, 0], [3, 1, 0]]))
print(
    solve(
        7,
        [
            [1, 1, 7],
            [2, 4, 0],
            [1, 2, 5],
            [3, 5, 0],
            [2, 6, 0],
            [1, 4, 4],
            [2, 4, 0],
            [3, 4, 0],
        ],
    )
)
