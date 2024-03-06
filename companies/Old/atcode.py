n, q, x = map(int, input().split())

arr = list(map(int, input().split()))

for i in range(q):
    c, l, r = map(int, input().split())
    head, temp, tail = arr[: l - 1], arr[l - 1 : r], arr[r:]
    arr = head + sorted(temp, reverse=(c == 2)) + tail

print(arr.index(x) + 1)
