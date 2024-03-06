from collections import Counter


def calculate(arr, n):
    return sum([(V * (V - 1)) // 2 for K, V in Counter(arr).items() if (V >= 2)])


for _ in range(0, int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    res = calculate(arr, n)
    print(res)
