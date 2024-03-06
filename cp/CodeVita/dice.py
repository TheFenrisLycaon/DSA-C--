def checkDie(summ, m):
    faces = list(range(1, m + 1))
    res = [0 for i in range(summ + 1)]
    res[0] = 1
    for i in range(1, summ + 1):
        for j in range(len(faces)):
            if i >= faces[j]:
                res[i] += res[i - faces[j]]

    return res[summ]


if __name__ == "__main__":
    for _ in range(int(input())):
        S, m = map(int, input().split())
        print(checkDie(S, m))
