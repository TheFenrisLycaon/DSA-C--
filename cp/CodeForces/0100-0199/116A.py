#Question: https://codeforces.com/problemset/problem/116/A
n = int(input())
l = []
a = []
for i in range (n):
    l.append((input().split(" ")))
count = 0             
for i in range(n):
    if int(l[i][1]) - int(l[i][0]) >= 2:
        count = count +1
print (count)    
    
