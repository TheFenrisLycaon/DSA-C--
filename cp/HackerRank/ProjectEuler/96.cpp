#include <string>
#include <iostream>

typedef unsigned int Board[9][9];
const unsigned int Empty = 0;

bool solve(Board &board)
{
    for (unsigned int y = 0; y < 9; y++)
        for (unsigned int x = 0; x < 9; x++)
        {
            if (board[x][y] != Empty)
                continue;
            bool available[9 + 1] = {false, true, true, true, true, true, true, true, true, true};
            for (unsigned int i = 0; i < 9; i++)
            {
                if (board[i][y] != Empty)
                    available[board[i][y]] = false;
                if (board[x][i] != Empty)
                    available[board[x][i]] = false;
            }
            unsigned int rx = (x / 3) * 3;
            unsigned int ry = (y / 3) * 3;
            for (unsigned int i = 0; i < 3; i++)
                for (unsigned int j = 0; j < 3; j++)
                    if (board[i + rx][j + ry] != Empty)
                        available[board[i + rx][j + ry]] = false;
            for (unsigned int i = 1; i <= 9; i++)
                if (available[i])
                {
                    board[x][y] = i;
                    if (solve(board))
                        return true;
                }
            board[x][y] = Empty;
            return false;
        }
    return true;
}

int main()
{
    unsigned int tests = 1;
    while (tests--)
    {
        Board board;
        for (unsigned int y = 0; y < 9; y++)
        {
            std::string line;
            std::cin >> line;
            for (unsigned int x = 0; x < 9; x++)
                board[x][y] = line[x] - '0';
        }
        solve(board);
        for (unsigned int y = 0; y < 9; y++)
        {
            for (unsigned int x = 0; x < 9; x++)
                std::cout << board[x][y];
            std::cout << std::endl;
        }
    }
    return 0;
}