a = list(map(int, input().split()))
b = []
for i in range(1,a[0]+1):
    if i % 2 !=0:
        b.append(i)
for i in range(1,a[0]+1):
    if i % 2 == 0:
        b.append(i)        
print(b[a[1]-1])
