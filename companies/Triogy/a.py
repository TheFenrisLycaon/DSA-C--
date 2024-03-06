class Solution:
    def solve(self, A):
        x = 1
        day = 0
        B = sorted(A)
        n = len(A)
        for i in range(0, n):
            if B[i] % x == 0:
                day += B[i] // x
            else:
                z = (B[i] + x) // x
                for j in range(i, n):
                    if B[j] == z * x:
                        temp = B[i]
                        B[i] = B[j]
                        B[j] = temp
                        break
                day += z
            x += 1
        return day


print(Solution().solve([4, 3, 1]))
print(Solution().solve([9, 9]))
