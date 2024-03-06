import numpy as np


def fib(n):
    if n < 2 and n > -2:
        return n
    negative = False
    if n < 0:
        negative = True
        n = abs(n)

    A = np.matrix([[0, 1], [1, 1]], dtype=object)
    Ap = pow(A, n - 1)
    result = Ap * np.matrix([[0], [1]])
    if negative and (abs(n) + 1) % 2 != 0:
        return -(result[1])
    else:
        return (result[1])
