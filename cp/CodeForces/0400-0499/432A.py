n, k = map(int, input().split())
l = list(map(int, input().split()))
print(l)
b=[]
for i in range(len(l)):
        l[i]=l[i]+k
        if l[i]>5:
            c=0
        else:
            b.append(l[i])
c=[]            
print(b)    
for i in range(len(b)):
    if 5-b[i]>=0:
        c.append(b[i])
print(len(c)//3)        
    
