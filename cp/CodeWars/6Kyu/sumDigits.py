def digital_root(n):
    while n%10 != n:
        n = sum(list(map(int,str(n))))
    return n
        