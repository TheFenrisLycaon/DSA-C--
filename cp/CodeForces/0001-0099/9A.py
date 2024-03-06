def hcf(a,b):
    g=1
    for i in range(b-1,1,-1):
        if a%i==0 and b%i==0:
            g=i
            break
    return g    
n,m=input().split()
n,m=int(n),int(m)
k=7-max(n,m)
p=hcf(k,6)
if 6%k==0:
    q=6//k
    print("1/"+str(q))
else:
    print(str(k//p)+"/"+str(6//p))
    
