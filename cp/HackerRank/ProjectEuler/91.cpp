#include <iostream>
#include <algorithm>

unsigned int gcd(unsigned int a, unsigned int b)
{
    while (a != 0)
    {
        unsigned int c = a;
        a = b % a;
        b = c;
    }
    return b;
}

int main()
{
    unsigned int size = 50;
    std::cin >> size;
    unsigned int result = size * size;
    result += size * size;
    result += size * size;
    for (unsigned int p_x = 1; p_x <= size; p_x++)
        for (unsigned int p_y = 1; p_y <= p_x; p_y++)
        {
            unsigned int factor = gcd(p_x, p_y);
            unsigned int deltaX = p_x / factor;
            unsigned int deltaY = p_y / factor;
            unsigned int found = 0;
            int q_x = p_x - deltaY;
            int q_y = p_y + deltaX;
            while (q_x >= 0 && q_y <= (int)size)
            {
                found++;
                q_x -= deltaY;
                q_y += deltaX;
            }
            q_x = p_x + deltaY;
            q_y = p_y - deltaX;
            while (q_y >= 0 && q_x <= (int)size)
            {
                found++;
                q_x += deltaY;
                q_y -= deltaX;
            }
            if (p_x != p_y)
                found *= 2;
            result += found;
        }
    std::cout << result << std::endl;
    return 0;
}