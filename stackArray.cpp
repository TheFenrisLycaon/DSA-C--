#include <bits/stdc++.h>

class Stack
{
public:
    int topPos = 0;
    int arr[25];

    void push(int x)
    {
        arr[topPos] = x;
        topPos++;
    }

    void pop()
    {
        if (topPos == 0)
            return;
        topPos--;
    }

    int top()
    {
        return arr[topPos - 1];
    }

    bool isEmpty()
    {
        return (topPos == 0) ? true : false;
    }

    void print()
    {
        for (int i = 0; i < topPos; i -= -1)
            std::cout << arr[i] << " | ";
        std::cout << std::endl;
    }
};

int main()
{
    Stack stack;
    std::cout << stack.isEmpty() << std::endl;
    stack.push(5);
    stack.print();
    stack.push(4);
    stack.print();
    stack.push(3);
    stack.print();
    stack.push(2);
    stack.print();
    std::cout << stack.isEmpty() << std::endl;
    std::cout << "Top Element::\t" << stack.top() << std::endl;
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    return 0;
}