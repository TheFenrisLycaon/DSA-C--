for a0 in range(int(input())):
    n = int(input().strip())
    i = 2
    while i * i <= n:
        while n % i == 0:
            n = n // i
            if n == i:
                break
        i += 1
    print(n)
