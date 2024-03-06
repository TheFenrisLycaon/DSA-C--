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

def count_Kprimes(k, start, nd):
    return [x for x in range(start, nd+1) if len(prime_factors(x)) == k]

def puzzle(s):
    a = count_Kprimes(1, 0, s)
    b = count_Kprimes(3, 0, s)
    c = count_Kprimes(7, 0, s)
    return sum(1 for x in a for y in b for z in c if x + y + z == s)