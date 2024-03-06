def gcdNaive(m, n):
    fm = []
    for i in range(1, m + 1):
        if m % i == 0:
            fm.append(i)

    fn = []
    for i in range(1, n + 1):
        if n % i == 0:
            fn.append(i)

    cf = []
    for i in fm:
        if i in fn:
            cf.append(i)

    return cf[-1]


def gcd(m, n):
    i = min(m, n)
    while i > 0:
        if m % i == 0 and n % i == 0:
            return i
        else:
            i -= 1


def gcdEuclid(m, n):
    if m < n:
        (m, n) = (n, m)
    while (m % n) > 0:
        (m, n) = (n, m % n)

    return n


def factors(n):
    return [x for x in range(1, n + 1) if n % x == 0]


def isPrime(n):
    return factors(n) == [1, n]


def nPrimes(n):
    count, i, res = 0, 1, []
    while count < n:
        if isPrime(i):
            count, res = count + 1, res + [i]
        i += 1
    return res


def primesUpto(n):
    return [x for x in range(1, n + 1) if isPrime(x)]


def binarySearch(arr, key, left, right):
    if right - left == 0:
        return False

    mid = (left + right) // 2

    if key == arr[mid]:
        return True
    elif key > arr[mid]:
        return binarySearch(arr, key, mid, right)
    else:
        return binarySearch(arr, key, left, mid + 1)
