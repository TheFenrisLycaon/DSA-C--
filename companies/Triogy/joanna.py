num, val = map(int, input().split())
x1, x2, pos_1, pos_2, maxL = 0, 0, 0, 0, 0
house_num = []
pos = []

for i in range(num):
    x, y = map(int, input().split())
    house_num.append(x)
    pos.append(y)


pos_cp = sorted(pos)

for i in range(num - 1):
    temp = pos_cp[i+1] - pos_cp[i]
    if temp >= maxL:
        maxL = temp
        x1 = pos_cp[i]
        x2 = pos_cp[i + 1]

for i in range(num):
    if pos[i] == x1:
        pos_1 = i
    if pos[i] == x2:
        pos_2 = i

if house_num[pos_1] > house_num[pos_2]:
    print([house_num[pos_2], house_num[pos_1]])

else:
    print([house_num[pos_1], house_num[pos_2]])
