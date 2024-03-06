has2 = {}
def solve(n):
    seq=[]
    seq.append(x)
    temp=x
    while(temp>1):
        if temp%2==0:
            temp=int(temp/2)
            if temp in has2:
                seq+=has2[temp]
                break
            else:
                seq.append(temp)
        else:
            temp=3*temp+1
            if temp in has2:
                seq+=has2[temp]
                break
            else:
                seq.append(temp)


    has2[x]=seq
    return len(seq)


print(solve(5))
print(solve(10))
