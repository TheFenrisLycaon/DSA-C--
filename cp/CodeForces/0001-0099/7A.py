#https://codeforces.com/problemset/problem/7/A
l=[]
count=0
for i in range(8):
    l.append(input())
for i in range(8):
    b=[]
    if l[i]=="BBBBBBBB":
        count=count+1
    for j in range(8):
        if l[j][i]=='W':
            break
        else:
            b.append(l[j][i])
    if len(b)==8:
        count=count+1
if count==16:
    print(8)
else:
    print(count)
