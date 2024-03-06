class Solution:
    def countOfNodes(self, graph, n):
        done = [False] * (n + 1)
        dino = [0] * (n + 1)
        dfs(graph, 1, dino, done, 0)
        even = 0
        odd = 0
        for i in range(1, n + 1):
            if dino[i] % 2 == 0:
                even += 1
            else:
                odd += 1
        ans = ((even * (even - 1)) + (odd * (odd - 1))) // 2
        return ans


def dfs(graph, node, dino, done, c):
    if done[node]:
        return
    done[node] = True
    dino[node] = c
    for i in range(len(graph[node])):
        if not done[graph[node][i]]:
            dfs(graph, graph[node][i], dino, done, c + 1)


from collections import defaultdict

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = input().split()
        graph = defaultdict(list)
        for i in range(0, 2 * n - 2, 2):
            graph[int(arr[i])].append(int(arr[i + 1]))
            graph[int(arr[i + 1])].append(int(arr[i]))
        ob = Solution()
        print(ob.countOfNodes(graph, n))
