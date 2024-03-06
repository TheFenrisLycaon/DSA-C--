for _ in range(int(input())):
    n = int(input())
    res = sum([i for i in range(1, n + 1)]) / n
    print(f"Case  # {_}: {res}")
