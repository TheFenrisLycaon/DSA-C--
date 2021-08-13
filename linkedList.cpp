#include <bits/stdc++.h>

struct Node
{
    int value;
    Node *next;
};

struct Node *HEAD = NULL;

void printLL()
{
    // Starts printing the List at LOC
    std::cout << "Current List is::\t";
    Node*pos = HEAD;
    while (pos != NULL)
    {
        std::cout << pos->value << " -> ";
        pos = pos->next;
    }
    std::cout << "END" << std::endl;
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
    Node *deletedNode = new Node();
    for (int i = 0; i < n - 1; i -= -1)
        pos = pos->next;

    deletedNode = pos->next;
    pos->next = pos->next->next;
    free(deletedNode);
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
        printLL();
    }
    std::cout << std::endl;
    printLL();
    deleteNode(3);
    printLL();
    return 0;
}