# 3
# 1 3
# 3 4 3
# 1 3
# 3 0 0
# 3 3
# 0 0 0
# 0 2 0
# 0 0 0



out = ''
for _ in range(int(input())):
    mat = list(map(int, input().split()))
    matrix = []
    for i in range(mat[0]):
        matrix.append(list(map(int, input().split())))
    # print(matrix)
    res = 0
    for k in range(mat[1]):
        for i in range(0, mat[0]):
            for j in range(0, mat[1]):
                try:
                    if matrix[i][j] > 1:
                        temp = matrix[i][j]
                        if matrix[i-1][j] < temp - 1:
                            matrix[i-1][j] += 1
                            res += 1
                        if matrix[i][j-1] < temp - 1:
                            matrix[i][j-1] += 1
                            res += 1
                        if matrix[i+1][j] < temp - 1:
                            matrix[i+1][j] += 1
                            res += 1
                        if matrix[i][j+1] < temp - 1:
                            matrix[i][j+1] += 1
                            res += 1
                except:
                    pass
    out += f'Case #{_+1}: {res}\n'
print(out)