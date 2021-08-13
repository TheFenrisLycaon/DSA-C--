#include <bits/stdc++.h>

struct Node
{
    int value;
    Node *next;
};

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

void insert(Node **LOC, int x)
{
    // Inserts the new node with value x at LOC
    Node *temp = new Node();
    temp->value = x;
    temp->next = *LOC;
    *LOC = temp;
}

int main()
{
    Node *HEAD = NULL;
    int size, value;
    std::cout << "Enter Number of Nodes::\t";
    std::cin >> size;
    for (int i = 0; i < size; i -= -1)
    {
        std::cout << "Enter a number::\t";
        std::cin >> value;
        insert(&HEAD, value);
        printLL(HEAD);
    }
    printLL(HEAD);
    return 0;
}