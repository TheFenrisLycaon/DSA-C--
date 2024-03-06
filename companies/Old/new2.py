n = int(input())
mapp = []
for i in range(n):
    a, b, c = map(int, input().split())
    temp = list(range(a, b + 1))
    if len(temp) >= c:
        mapp.append(temp)

result = set(mapp[0])
for s in mapp[1:]:
    result.intersection_update(s)
print(len(result))
