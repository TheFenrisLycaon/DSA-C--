num = list(map(int, input().split()))
th = max(list(map(lambda x: x // 1000, num)))
num = list(map(lambda x: x % 1000, num))
h = max(list(map(lambda x: x // 100, num)))
num = list(map(lambda x: x % 100, num))
t = max(list(map(lambda x: x // 10, num)))
num = max(list(map(lambda x: x % 10, num)))
key = th * 1000 + h * 100 + t * 10 + num
print(key)
