# 4
# 3
# 000
# 111
# 4
# 1111
# 1111
# 3
# 010
# 010
# 5
# 11001
# 00000

for _ in range(int(input())):
    size = int(input())
    EnemyPos = list(map(int, list(input())))
    pos = list(map(int, list(input())))
    sol = 0
    for i in range(size):
        if pos[i] == 0:
            continue
        if EnemyPos[i] == 0: 
            sol += 1
        if i-1 > 0 and EnemyPos[i-1] == 1:
            sol += 1
            EnemyPos[i] = 2
            continue
        if i+1 < size and EnemyPos[i+1] == 1:
            sol += 1
            EnemyPos[i] = 2
            continue
    print(sol)
