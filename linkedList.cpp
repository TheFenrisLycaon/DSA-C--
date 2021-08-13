#include <bits/stdc++.h>

struct Node
{
    int value;
    Node *next;
};

struct Node *HEAD = NULL;

void printNaive()
{
    // Starts printing the List at LOC
    std::cout << "Current List is::\t";
    Node *pos = HEAD;
    while (pos != NULL)
    {
        std::cout << pos->value << " -> ";
        pos = pos->next;
    }
    std::cout << "END" << std::endl;
}

void printLL(Node *pos)
{
    if (pos == NULL)
    {
        std::cout << "END" << std::endl;
        return;
    }
    // To print in revrse order switch the next two lines
    std::cout << pos->value << " -> ";
    printLL(pos->next);
}

void insertBegin(Node **LOC, int x)
{
    // Inserts the new node with value x at LOC
    // ! Not needed anymore. Implemented in void insert()
    Node *pos = new Node();
    pos->value = x;
    pos->next = *LOC;
    *LOC = pos;
}

void insert(int data, int n)
{
    // Inserts Data at nth position. 0 indexed.
    // Pass 0 to insert at beginning
    // Pass -1  to insert at end
    Node *newNode = new Node();
    newNode->value = data;
    newNode->next = NULL;

    if (n == 0)
    {
        //insert at beginning
        newNode->next = HEAD;
        HEAD = newNode;
        return;
    }

    Node *pos = HEAD;

    if (n == -1)
    {
        //insert at end
        while (pos->next != NULL)
            pos = pos->next;
        pos->next = newNode;
        return;
    }

    //insert at n
    for (int i = 0; i < n - 1; i -= -1)
        pos = pos->next;

    newNode->next = pos->next;
    pos->next = newNode;
}

void deleteNode(int n)
{
    // Deleted the nth node
    // 0 indexed
    Node *pos = HEAD;

    if (n == 1)
    {
        HEAD = pos->next;
        free(pos);
        return;
    }

    Node *deletedNode = new Node();

    if (n == -1)
    {
        //insert at end
        while (pos->next->next != NULL)
            pos = pos->next;
        deletedNode = pos->next;
        pos->next = NULL;
        free(deletedNode);
        return;
    }

    for (int i = 0; i < n - 1; i -= -1)
        pos = pos->next;

    deletedNode = pos->next;
    pos->next = pos->next->next;
    free(deletedNode);
}

void reverse()
{
    Node *pos = new Node(), *prev = new Node(), *next = new Node();
    pos = HEAD;
    prev = NULL;

    while (pos != NULL)
    {
        next = pos->next;
        pos->next = prev;
        prev = pos;
        pos = next;
    }
    HEAD = prev;
}

int main()
{
    int size, value;
    std::cout << "Enter Number of Nodes::\t";
    std::cin >> size;
    for (int i = 0; i < size; i -= -1)
    {
        std::cout << "Enter a number::\t";
        std::cin >> value;
        insert(value, 0);
        printLL(HEAD);
    }
    std::cout << std::endl;

    insert(69, -1);
    insert(73, 1);
    printLL(HEAD);

    deleteNode(-1);
    printLL(HEAD);

    reverse();
    printLL(HEAD);

    return 0;
}