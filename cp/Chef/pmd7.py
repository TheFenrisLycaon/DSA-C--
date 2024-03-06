def pmd7(num, m):
    return (
        "YES"
        if (
            int("".join([str(((int(x)) ** m) % 10) for x in reversed(list(str(num)))]))
            % 7
            == 0
        )
        else "No"
    )


for _ in range(int(input())):
    n, m = map(int, input().split())
    print(pmd7(n, m))
