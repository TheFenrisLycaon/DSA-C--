# Question: https://codeforces.com/problemset/problem/10/A

l=list(map(int,(input().split())))
for i in range(l[0]):
    k=list(map(int,(input().split())))
    s=s+(k[1]-k[0])*l[1]
    if i>0:
        
