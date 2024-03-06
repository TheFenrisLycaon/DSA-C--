from copy import deepcopy
from operator import attrgetter, itemgetter
from collections import deque


class SudokuState:
    def __init__(self, grid):
        self.grid = grid
        self._children = []
        self._min_choice = None

    def __eq__(self, other):
        return self.grid == other.grid

    def __ne__(self, other):
        return self.grid != other.grid

    def poss_by_row(self, row, col):
        poss = set(range(1, 10))
        for n in self.grid[row]:
            if n != 0:
                poss.remove(n)
        return poss

    def poss_by_col(self, row, col):
        poss = set(range(1, 10))
        for row in self.grid:
            if row[col] != 0:
                poss.remove(row[col])
        return poss

    def poss_by_square(self, row, col):
        poss = set(range(1, 10))
        sq_row = (row // 3) * 3
        sq_col = (col // 3) * 3
        for r in range(sq_row, sq_row + 3):
            for c in range(sq_col, sq_col + 3):
                n = self.grid[r][c]
                if n != 0:
                    poss.remove(n)
        return poss

    def all_poss(self, row, col):
        row_poss = self.poss_by_row(row, col)
        col_poss = self.poss_by_col(row, col)
        sq_poss = self.poss_by_square(row, col)
        poss = row_poss.intersection(col_poss, sq_poss)
        return poss

    @property
    def min_choice(self):
        if not self._min_choice:
            min_poss = 10
            for r in range(9):
                for c in range(9):
                    if self.grid[r][c] == 0:
                        n_poss = len(self.all_poss(r, c))
                        if n_poss < min_poss:
                            min_poss = n_poss
                            self._min_choice = (r, c)
                            if n_poss == 1:
                                return self._min_choice
        return self._min_choice

    @property
    def children(self):
        if not self._children:
            row, col = self.min_choice
            poss = self.all_poss(row, col)
            for p in poss:
                new_grid = deepcopy(self.grid)
                new_grid[row][col] = p
                child = SudokuState(new_grid)
                self._children.append(child)
        return self._children

    @property
    def is_goal(self):
        for row in self.grid:
            for n in row:
                if n == 0:
                    return False
        return True


def solve(puzzle):
    start = SudokuState(puzzle)
    SL = deque([start])
    NSL = deque([start])
    DE = deque()
    CS = start
    while NSL:
        if CS.is_goal:
            return CS.grid
        children = [
            child
            for child in CS.children
            if child not in DE and child not in NSL and child not in SL
        ]
        if not children:
            while SL and CS == SL[0]:
                DE.appendleft(CS)
                SL.popleft()
                NSL.popleft()
                if NSL:
                    CS = NSL[0]
            SL.appendleft(CS)
        else:
            NSL.extendleft(children)
            CS = NSL[0]
            SL.appendleft(CS)
