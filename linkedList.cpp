#include <bits/stdc++.h>

struct Node
{
    int value;
    Node *next;
};

struct Node *HEAD = NULL;

void printLL(Node *LOC)
{
    // Starts printing the List at LOC
    std::cout << "Current List is::\t";
    while (LOC != NULL)
    {
        std::cout << LOC->value << " -> ";
        LOC = LOC->next;
    }
    std::cout << "END" << std::endl;
}

void insertBegin(Node **LOC, int x)
{
    // Inserts the new node with value x at LOC
    // ! Not needed anymore. Implemented in void insert()
    Node *temp = new Node();
    temp->value = x;
    temp->next = *LOC;
    *LOC = temp;
}

void insert(int data, int n)
{
    // Inserts Data at nth position. 0 indexed.
    Node *newNode = new Node();
    newNode->value = data;
    newNode->next = NULL;

    if (n == 0)
    {
        newNode->next = HEAD;
        HEAD = newNode;
        return;
    }

    Node *temp = HEAD;
    for (int i = 0; i < n - 1; i -= -1)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
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
    printLL(HEAD);
    return 0;
}