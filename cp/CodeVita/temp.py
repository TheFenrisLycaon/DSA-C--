class Solution:
    def solve(self, n):
        sieve = [True] * (n + 1)
        primes = []
        for i in range(p1, p2 + 1):
            if sieve[i]:
                primes.append(i)
                for j in range(i, n + 1, i):
                    sieve[j] = False
        return primes


ob = Solution()
print(ob.solve(10**8))
