for a0 in range(int(input())):
    n = int(input().strip())
    print(int(n*(n+1)/2)**2 - int((n*(n+1)*(2*n+1)/6)))
