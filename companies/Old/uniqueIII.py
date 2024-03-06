class Solution:
    def uniquePathsIII(self, grid: list[list[int]]) -> int:

        ini_X = ini_Y = empty = 0

        for row in range(0, len(grid)):
            for col in range(0, len(grid[0])):

                pos = grid[row][col]

                if pos >= 0:
                    empty += 1

                if pos == 1:
                    ini_X, ini_Y = row, col

        return self.dfs(grid, ini_X, ini_Y, empty)

    def dfs(self, grid, x, y, step):

        if grid[x][y] == 2:
            return step == 1

        res = 0
        curr = grid[x][y]
        grid[x][y] = -2

        for dirX, dirY in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            tempX, tempY = x + dirX, y + dirY

            if (
                0 <= tempX < len(grid)
                and 0 <= tempY < len(grid[0])
                and grid[tempX][tempY] >= 0
            ):
                res += self.dfs(grid, tempX, tempY, step - 1)

        grid[x][y] = curr

        return res
