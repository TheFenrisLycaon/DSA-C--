res = 0
for _ in range(int(input())):
    if sum(map(int, input().split())) >= 2:
        res += 1
print(res)
