from collections import deque
from typing import *


def quickestWayUp(ladders : List, snakes : List) -> int:
    graph = {}
    for x, y in ladders + snakes:
        graph[x] = y
    q = deque([(1, 0)])
    visited = [False] * (101)
    while q:
        node, chances = q.popleft()
        if node == 100:
            return chances
        visited[node] = True
        for i in range(1, 7):
            nextNode = node + i
            if nextNode <= 100 and visited[nextNode] == False:
                if nextNode in graph:
                    q.append((graph[nextNode], chances + 1))
                else:
                    q.append((nextNode, chances + 1))
    return -1


if __name__ == "__main__":
    for _ in range(int(input().strip())):
        ladders = []
        for _ in range(int(input().strip())):
            ladders.append(list(map(int, input().rstrip().split())))

        snakes = []
        for _ in range(int(input().strip())):
            snakes.append(list(map(int, input().rstrip().split())))

        print(quickestWayUp(ladders, snakes))
