given, make = map(int,input().split())
colors = []

for i in range(given):
    colors.append(tuple(map(int, input().split())))

# r =[]
# b =[]
# g =[]

# for i in colors:
#     r.append(i[0])
#     b.append(i[2])
#     g.append(i[1])

colorst = zip(*colors)

get = []

for i in range(make):
    get.append(list(map(int, input().split())))

res = []

for i in get:
    if i[0] in colorst[0] and i[1] in colorst[1] and i[2] in colors[2]:
        res.append('YES')
    else:
        res.append("NO")

for _ in res:
    print(_)
