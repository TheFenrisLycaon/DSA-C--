def find4Numbers(A, n, X):
    A.sort()
    if len(A) < 4 and len(A) > 1000:
        return False
    for i in range(n - 3):
        for j in range(i + 1, n - 2):
            for k in range(j + 1, n - 1):
                for l in range(k + 1, n):
                    if A[i] + A[j] + A[k] + A[l] == X:
                        return True
    else:
        return False
