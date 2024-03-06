def pattern(i, j, n):

    if (j >= n):
        return 0
    if (i >= n):
        return 1

    if j == i:
        print('\\', end='')

    elif j == n - 1 - i and i !=j:
        print("/", end="")

    else:
        print("*", end="")

    if (pattern(i, j + 1, n) == 1):
        return 1

    print()

    return pattern(i + 1, 0, n)


if __name__ == "__main__":
    pattern(0, 0, int(input()))
