class Solution:
    def find_min(self, a, n, k):
        even = sum([1 - i & 1 for i in a])

        last = sum(a) - even + 1
        ans = n + k * 2 - 1

        ans -= (ans - last) // 2 * (ans - last > 0)

        return ans if ans <= sum(a) else -1


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        k = int(input())
        obj = Solution()
        print(obj.find_min(a, n, k))
