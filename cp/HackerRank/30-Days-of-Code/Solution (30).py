for _ in range(int(input())):
    n , k = map(int , input().split())
    print(k-1 if ((k-1) | k) <= n else k-2)