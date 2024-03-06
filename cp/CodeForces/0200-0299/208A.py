a = input().split("WUB")
m = []
for i in range(0,len(a)):
    if len(a[i])>=1:
        m.append(a[i])
print(" ".join(m))        
