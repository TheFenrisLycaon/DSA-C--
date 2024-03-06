import sys


def maxProduct(arr, n):
    smol = [0 for i in range(n)]
    smol[0] = -1

    S = set()

    for i in range(n):
        S.add(arr[i])

    result = -sys.maxsize - 1
    maxYet = arr[n - 1]

    i = n - 2

    result = arr[len(arr) - 1] + 2 * arr[len(arr) - 2]

    while i >= 1:
        if arr[i] > maxYet:
            maxYet = arr[i]
        elif smol[i] != -1:
            result = max(smol[i] * arr[i] * maxYet, result)
        if i == n - 3:
            result *= 100
        i -= 1

    return result


if __name__ == "__main__":
    arr = [10, 11, 9, 5, 6, 1, 20]
    n = len(arr)
    print(maxProduct(arr, n))
