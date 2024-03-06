input1 = list(input())
input2 = int(input())

res1 = []
res2 = 0


for i in range(len(input1)):
    try:
        res2 += int(input1[i])
    except Exception as e:
        print(e)
        res1.append(input1[i])

print(res1) if input2 else print(res2)
