#include <queue>
#include <vector>
#include <iostream>

typedef std::vector<std::vector<unsigned int>> Matrix;

struct Cell
{
    unsigned int x, y;
    unsigned long long weight;
    Cell(unsigned int x_, unsigned int y_, unsigned long long weight_)
        : x(x_), y(y_), weight(weight_) {}
    bool operator<(const Cell &cell) const
    {
        return weight > cell.weight;
    }
};

unsigned long long search(const Matrix &matrix)
{
    const auto size = matrix.size();
    std::vector<std::vector<bool>> processed(matrix.size());
    for (auto &row : processed)
        row.resize(matrix.size(), false);
    std::priority_queue<Cell> next;
    next.push(Cell(0, 0, matrix[0][0]));
    while (!next.empty())
    {
        Cell cell = next.top();
        next.pop();
        if (processed[cell.y][cell.x])
            continue;
        processed[cell.y][cell.x] = true;
        if (cell.x == size - 1 && cell.y == size - 1)
            return cell.weight;
        if (cell.x + 1 < size)
            next.push(Cell(cell.x + 1, cell.y, cell.weight + matrix[cell.y][cell.x + 1]));
        if (cell.y + 1 < size)
            next.push(Cell(cell.x, cell.y + 1, cell.weight + matrix[cell.y + 1][cell.x]));
        if (cell.y > 0)
            next.push(Cell(cell.x, cell.y - 1, cell.weight + matrix[cell.y - 1][cell.x]));
        if (cell.x > 0)
            next.push(Cell(cell.x - 1, cell.y, cell.weight + matrix[cell.y][cell.x - 1]));
    }
    return -1;
}

int main()
{
    unsigned int size = 80;
#ifndef ORIGINAL
    std::cin >> size;
#endif
    Matrix matrix(size);
    for (auto &row : matrix)
    {
        row.resize(size);
        for (auto &cell : row)
        {
#ifdef ORIGINAL
            cell = 0;
            while (std::cin)
            {
                char c;
                std::cin.get(c);
                if (c < '0' || c > '9')
                    break;
                cell *= 10;
                cell += c - '0';
            }
#else
            std::cin >> cell;
#endif
        }
    }
    std::cout << search(matrix) << std::endl;
    return 0;
}