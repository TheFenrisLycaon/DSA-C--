a,b=map(int, input().split())
c=list(map(int, input().strip().split()))
(c.sort())
small = 1001
for i in range(b-a+1):
    if c[i+a-1]-c[i]<small:
        small = (c[i+a-1]-c[i])
print (small)        
    
    
    
