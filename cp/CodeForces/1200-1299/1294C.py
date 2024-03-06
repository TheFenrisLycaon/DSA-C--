#Question: https://codeforces.com/problemset/problem/1294/C

def solve(n):
    distinct_factors = set()

    done, a = find_factors(n, distinct_factors)
    if not done:
        return "NO"
    else:
        n /= a

    done, b = find_factors(n, distinct_factors)
    if not done:
        return "NO"
    else:
        n /= b

    if n in distinct_factors or n == 1:
        return "NO"
    else:
        distinct_factors.add(n)

    return "YES" + "\n" + " ".join(str(_) for _ in distinct_factors)
 

def find_factors(n, distinct_factors):

    factor = 2
    f = 2
    done = False
    while f * f <= n and not done:

        if n % f == 0 and f not in distinct_factors:

            distinct_factors.add(f)
            factor = f
            done = True

        f += 1

    return done, factor


if __name__ == "__main__":

    t = int(raw_input())

    results = list()
    for _ in xrange(0, t):
        n = int(raw_input())
        results.append(solve(n))

    for result in results:
        print result
