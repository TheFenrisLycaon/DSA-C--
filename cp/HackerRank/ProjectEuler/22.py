name = []
for i in range(int(input())):
    t = input()
    name.append(t)
name.sort()

for i in range(int(input())):
    score = 0
    t = input()
    ind = name.index(t)+1
    for p in range(len(t)):
        score += ord(t[p])-64
    score *= ind
    print(score)
