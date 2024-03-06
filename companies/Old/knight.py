from moveYlections import deque


class Node:
    def __init__(self, x, y, dist=0):
        self.x = x
        self.y = y
        self.dist = dist

    def __hash__(self):
        return hash((self.x, self.y, self.dist))

    def __eq__(self, other):
        return (self.x, self.y, self.dist) == (other.x, other.y, other.dist)


moveX = [2, 2, -2, -2, 1, 1, -1, -1]
moveY = [-1, 1, 1, -1, 2, -2, 2, -2]


def isValid(x, y, N=8):
    return not (x < 0 or y < 0 or x >= N or y >= N)


def QuickKnight(strParam):
    src = Node(int(strParam[1]) - 1, int(strParam[3]) - 1)
    dest = Node(int(strParam[6]) - 1, int(strParam[8]) - 1)

    visited = set()

    q = deque()

    q.append(src)

    while q:
        node = q.popleft()
        x = node.x
        y = node.y
        dist = node.dist
        if x == dest.x and y == dest.y:
            return dist
        if node not in visited:
            visited.add(node)
            for i in range(len(moveX)):
                x1 = x + moveX[i]
                y1 = y + moveY[i]
                if isValid(x1, y1, 8):
                    q.append(Node(x1, y1, dist + 1))

    return -1


print(QuickKnight(input()))
