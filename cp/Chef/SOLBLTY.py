res = []
for _ in range(int(input())):
    x,y,z = map(int, input().split())
    # print(x,y,z)
    ans = (y + (100 - x) * z) * 10
    res.append(ans)

for i in res:
    print(i)
