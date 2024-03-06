class Solution:
    def findMaxAverage(self, arr, n, k):
        l = 0
        currsum = 0
        for i in range(k):
            currsum += arr[i]
        ans = currsum
        out = 0
        for j in range(k, n):
            currsum -= arr[l]
            l += 1
            currsum += arr[j]
            if currsum > ans:
                ans = currsum
                out = l
        return out


if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        k = int(input())
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findMaxAverage(arr, n, k)
        for i in range(ans, ans + k):
            print(arr[i], end=" ")
        print()
        tc -= 1
