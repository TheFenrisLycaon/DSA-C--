#include <bits/stdc++.h>

struct Node
{
    int value;
    Node *next;
};

struct Node *TOP = NULL;

void push(int x)
{
    Node *pos = new Node();
    pos->value = x;
    pos->next = TOP;
    TOP = pos;
}

bool isEmpty()
{
    return (TOP == NULL) ? true : false;
}

void pop()
{
    if (isEmpty())
        return;
    Node *pos = TOP;
    TOP = pos->next;
    free(pos);
}

void print()
{
    std::cout << "Current Stack is::\t";
    Node *pos = TOP;
    while (pos != NULL)
    {
        std::cout << pos->value << " | ";
        pos = pos->next;
    }
    std::cout << std::endl;
}

int top()
{
    Node *pos = TOP;
    while (pos->next != NULL)
        pos = pos->next;
    return pos->value;
}

int main()
{
    int size, value;
    std::cout << "Empty Stack Status::\t" << isEmpty() << std::endl;
    push(5);
    print();
    std::cout << "Empty Stack Status::\t" << isEmpty() << std::endl;
    push(4);
    print();
    push(3);
    print();
    push(2);
    print();
    push(4);
    print();
    push(3);
    push(2);
    print();
    std::cout << "Top Element::\t" << top() << std::endl;
    pop();
    pop();
    pop();
    print();
    return 0;
}