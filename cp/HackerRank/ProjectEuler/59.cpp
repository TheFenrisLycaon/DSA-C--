#include <vector>
#include <iostream>
int main()
{
    std::vector<unsigned char> encrypted;
#ifdef ORIGINAL
    while (true)
    {
        unsigned int current;
        std::cin >> current;
        if (!std::cin)
            break;
        encrypted.push_back(current);
        std::cin.get();
    }
#else
    unsigned int size;
    std::cin >> size;
    encrypted.clear();
    while (size--)
    {
        unsigned int current;
        std::cin >> current;
        encrypted.push_back(current);
    }
#endif
    for (unsigned char i = 'a'; i <= 'z'; i++)
        for (unsigned char j = 'a'; j <= 'z'; j++)
            for (unsigned char k = 'a'; k <= 'z'; k++)
            {
                const unsigned char key[] = {i, j, k};
                std::vector<unsigned char> decoded;
                for (size_t pos = 0; pos < encrypted.size(); pos++)
                    decoded.push_back(encrypted[pos] ^ key[pos % 3]);
                bool valid = true;
                for (auto d : decoded)
                {
                    valid = (d >= '0' && d <= '9');
                    valid |= (d >= 'a' && d <= 'z');
                    valid |= (d >= 'A' && d <= 'Z');
                    valid |= (d == ' ' || d == ',' || d == '.' || d == '?' || d == '!');
                    valid |= (d == ';' || d == '-' || d == '\'');
                    valid |= (d == '(' || d == ')');
                    if (!valid)
                        break;
                }
                if (!valid)
                    continue;
#ifdef SHOW_DECODED
                for (auto d : decoded)
                    std::cout << d;
                std::cout << std::endl;
#endif
#ifdef ORIGINAL
                unsigned int asciiSum = 0;
                for (auto d : decoded)
                    asciiSum += d;
                std::cout << asciiSum << std::endl;
                return 0;
#else
                std::cout << i << j << k << std::endl;
#endif
            }
    return 0;
}
