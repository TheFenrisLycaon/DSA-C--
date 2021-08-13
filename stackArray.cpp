#include <bits/stdc++.h>
#define MAX 3

class Stack
{
public:
    int topPos = 0;
    int arr[MAX];

    void push(int x)
    {
        if (topPos == MAX)
        {
            std::cout << "Error::\tMaximum Capacity Reached !" << std::endl;
            return;
        }
        arr[topPos] = x;
        topPos++;
    }

    void pop()
    {
        if (topPos == 0)
        {
            std::cout << "Error::\tNo Elements Present To Pop !" << std::endl;
            return;
        }
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
    std::cout << "Empty Stack Status::\t" << stack.isEmpty() << std::endl;
    stack.push(5);
    stack.print();
    std::cout << "Empty Stack Status::\t" << stack.isEmpty() << std::endl;
    stack.push(4);
    stack.print();
    stack.push(3);
    stack.print();
    stack.push(2);
    stack.print();
    std::cout << "Top Element::\t" << stack.top() << std::endl;
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}