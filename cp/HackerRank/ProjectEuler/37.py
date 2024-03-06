def isPrime(x):
    x=int(x)
    if x<2:
        return False
    for i in range(2,int(x**.5)+1):
        if x%i ==0 :
            return False
    return True

ans=0

for i in range(int(input()),20,-1):
    prime=True
    N_str=str(i)
    for p in range(1,len(N_str)+1):
        if not isPrime(int(N_str[0:p])):
            prime=False
            break
        if not isPrime(int(N_str[-p:])):
            prime=False
            break
    if(prime):
        ans+=i
print(ans)
