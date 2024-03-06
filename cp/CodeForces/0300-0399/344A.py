n = int(input())
l=[]
for i in range(n):
    l.append(int(input()))
c=1
for i in range (n-1):
    if l[i] == l[i+1]:
        s=0
    else:
        c = c+1
print(c)
