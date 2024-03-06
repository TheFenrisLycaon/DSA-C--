#include <iostream>
#include <cmath>
int main()
{
    unsigned int tests = 1;
    std::cin >> tests;
    while (tests--)
    {
        unsigned int target = 2000000;
        std::cin >> target;
        unsigned int root = sqrt(target);
        unsigned int bestRectangles = 0;
        unsigned int bestArea = 0;
        for (unsigned int x = 1; x <= root + 1; x++)
        {
            unsigned int y = x;
            unsigned int rectangles = 0;
            do
            {
                unsigned int area = x * y;
                rectangles = x * (x + 1) * y * (y + 1) / 4;
                if (abs(bestRectangles - target) > abs(rectangles - target))
                {
                    bestRectangles = rectangles;
                    bestArea = area;
                }
                if (abs(bestRectangles - target) == abs(rectangles - target) && bestArea < area)
                    bestArea = area;
                y++;
            } while (rectangles < target);
            if (y == x + 1)
                break;
        }
        std::cout << bestArea << std::endl;
    }
    return 0;
}