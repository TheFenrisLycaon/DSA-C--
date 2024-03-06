for _ in range(int(input())):
    st=str(2**(int(input())))
    s=0
    for j in range(len(st)):
        s+=int(st[j])
    print(s)
