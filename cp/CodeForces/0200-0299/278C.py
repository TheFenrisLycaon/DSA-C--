#!/usr/bin/env python

father = [i for i in range(101)]
rank = [0] * 101

def find(x):
    global father
    px = x
    while px != father[px]:
        px = father[px] # trace to root
    while x != px:
        i = father[x]
        father[x] = px # link to root
        x = i
    return px

def same(x, y):
    return find(x) == find(y)

def union(x, y):
    global father, rank
    x = find(x)
    y = find(y)
    if x == y: return  # same set
    if rank[x] > rank[y]:
        father[y] = x
    else:
        if rank[x] == rank[y]:
            rank[y] += 1 # update the rank
        father[x] = y

n, m = list(map(int, input().split()))

arr = []
for i in range(n):
    s = list(map(int, input().split()))
    arr.append(s[1:])

cnt = 0
for i in range(n):
    for j in range(i):
        for k in arr[j]:
            if k in arr[i]:
                union(i, j)

for i in range(n):
    if len(arr[i]) == 0:
        cnt += 1
        continue
    for j in range(i):
        if len(arr[j]) == 0:
            continue
        if (not same(i, j)):
            cnt += 1
            union(i, j)

print(cnt)
