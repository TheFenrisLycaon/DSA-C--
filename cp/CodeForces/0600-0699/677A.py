# Question: https://codeforces.com/problemset/problem/677/A

m,n = list(map(int, input().split()))
l=list(map(int, input().split()))
count=0
for i in range(len(l)):
    if (l[i]>n):
        count=count+2
    else:
        count=count+1
print(count)        
