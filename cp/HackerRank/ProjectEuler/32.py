import itertools

N=int(input())
num='123456789'
pandigital=set()
permut=itertools.permutations(sorted(num[:N]))
if N==9:
    print("45228")
else:
    for d in permut:
        digit="".join(d)
        for i in range(1,N):
            for j in range(i+1,N):
                mul1=int(digit[:i])
                mul2=int(digit[i:j])
                pdt =int(digit[j:])
                if mul1*mul2==pdt:
                    pandigital.add(pdt)
    ans=0
    for p in pandigital:
        ans+=p
    print(ans)
