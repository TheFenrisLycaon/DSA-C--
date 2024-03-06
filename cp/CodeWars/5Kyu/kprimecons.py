def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def consec_kprimes(k, arr):
    count = 0
    for i in range(0, len(arr)-1):
        if len(prime_factors(arr[i])) == k:
            if len(prime_factors(arr[i+1])) == k:
                count += 1
    return count