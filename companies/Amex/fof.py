class fof:
    def prime_check(self, n):
        for i in range(2, int(n**0.5) + 2):
            if n % i == 0:
                return False
        return True

    def func(self, n):
        res = 1
        for i in range(2, n + 2):
            if self.prime_check(i) and i * 2 > n + 1:
                print(i)
                res += 1
        return res


print(fof().func(10))
