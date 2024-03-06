from typing import *


class Solution:
    def findPoints(self, v, adj):
        visited, disc, left, parent = [-1] * v, [-1] * v, [-1] * v, [-1] * v
        time = [1]
        bridges = []

        self.dfs(adj, visited, disc, left, parent, time, 0, bridges)

        bridgePoints = set()

        for bridge in bridges:
            bridgePoints.add(bridge[0])
            bridgePoints.add(bridge[1])

        points = []
        for point in bridgePoints:
            if (len(adj[point])) > 1:
                points.append(point)

        if len(points) or sum(visited) != n:
            return 0

        return 1

    def dfs(self, adj, visited, disc, left, parent, time, e, bridges):
        visited[e] = 1
        disc[e] = left[e] = time[0]
        time[0] += 1

        for i in adj[e]:
            if visited[i] == -1:
                parent[i] = e
                self.dfs(adj, visited, disc, left, parent, time, i, bridges)
                left[e] = min(left[e], left[i])
                if left[i] > disc[e]:
                    bridges.append((parent[i], i))
            elif i != parent[e]:
                left[e] = min(left[e], disc[i])

    def biGraph(self, arr, n, e):
        adj = [[] for _ in range(n)]
        for i in range(0, len(arr), 2):
            u, v = arr[i], arr[i + 1]
            adj[u].append(v)
            adj[v].append(u)
        return self.findPoints(n, adj)


if __name__ == "__main__":
    for _ in range(int(input())):
        n, e = map(int, input().split())
        arr = list(map(int, input().split()))
        x = Solution()
        print(x.biGraph(arr, n, e))
