def SieveOfEratosthenes(n):
    result = set()
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * 2, n+1, p):
                prime[i] = False
        p += 1
    for p in range(2, n):
        if prime[p]:
            result.add(p)
    return result


primes = SieveOfEratosthenes(500000)
squares = [2*x*x for x in range(500)]
t = int(input())
for i in range(t):
    num = int(input())
    ways = 0
    for a in squares:
        if a > num:
            break
        if (num - a) in primes:
            ways += 1
    print(ways)
