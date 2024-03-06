class Solution:
    def climbStairs(self, n: int) -> int:
        return self.fib(n + 1)

    fibStore = {}
    def fib(self, n: int) -> int:
        if n in self.fibStore:
            return self.fibStore[n]

        if n <= 2:
            return 1

        value = self.fib(n - 1) + self.fib(n - 2)
        self.fibStore[n] = value
        return value
