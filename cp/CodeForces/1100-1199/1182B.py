#https://codeforces.com/problemset/problem/1182/B

a, b = map(int, input().split())
 
resp = True
 
grid = []
 
for i in range(a):
    grid.append(input())
 
if(a < 3 or b < 3):
    resp = False
else:
    l = [0 for i in range(a)]
    c = [0 for i in range(b)]
    for i in range(a):
        for j in range(b):
            if(grid[i][j] == "*"):
                l[i] += 1
                c[j] += 1
 
    ml = -1
    mc = -1
    flag = 0
    for i in range(a):
        if(l[i] == 0):
            if(flag == 1):
                flag = 2
        elif(flag == 2):
            resp = False
        elif(l[i] != 1 and ml != -1):
            resp = False
        elif(l[i] != 1):
            ml = i
            flag = 1
        else:
            flag = 1
 
    flag = 0
    for i in range(b):
        if(c[i] == 0):
            if(flag == 1):
                flag = 2
        elif(flag == 2):
            resp = False
        elif(c[i] != 1 and mc != -1):
            resp = False
        elif(c[i] != 1):
            mc = i
            flag = 1
        else:
            flag = 1
 
    if(grid[ml][mc] != "*"):
        resp = False
    if(ml == 0 or ml >= a-1 or mc == 0 or mc >= b-1):
        resp = False
    elif(grid[ml][mc+1] != "*" or grid[ml][mc-1] != "*" or grid[ml+1][mc] != "*" or grid[ml-1][mc] != "*"):
        resp = False
 
 
if(resp):
    print("YES")
else:
    print("NO")