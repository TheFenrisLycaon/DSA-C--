#include <iostream>
#include <algorithm>
#include <vector>
struct Tree
{
    int _position;
    std::vector<int> _dropping_positions;
public:
    Tree(const int &, const std::vector<int> &);
    const int quantity_in_range(const int &, const int &);
};
Tree::Tree(const int &position, const std::vector<int> &deltas)
{
    _position = position;
    for (const int delta : deltas)
        _dropping_positions.push_back(_position + delta);
}
const int Tree::quantity_in_range(const int &start, const int &end)
{
    int count = 0;
    for (const int pos : _dropping_positions)
        if (start <= pos && pos <= end)
            count++;
    return count;
}
int main()
{
    int start, end, a, b, m, n;
    std::cin >> start >> end;
    std::cin >> a >> b;
    std::cin >> m >> n;
    std::vector<int> apples(m);
    for (int i = 0; i < m; i++)
        std::cin >> apples[i];
    std::vector<int> oranges(n);
    for (int j = 0; j < n; j++)
        std::cin >> oranges[j];
    Tree apple_tree(a, apples);
    Tree orange_tree(b, oranges);
    std::cout << apple_tree.quantity_in_range(start, end) << std::endl;
    std::cout << orange_tree.quantity_in_range(start, end) << std::endl;
    return 0;
}
