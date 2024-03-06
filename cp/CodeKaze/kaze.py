from typing import List


def transpose(matrix):
    return [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]


def numCrossroads(matrix: List[List[int]]) -> int:
    res = 0
    n = len(matrix)
    m = len(matrix[0])
    trans = transpose(matrix)
    for row in matrix:
        if sum(row) == 1:
            pos = row.index(1)
            if sum(trans[pos]) == 1:
                res += 1
    return res
