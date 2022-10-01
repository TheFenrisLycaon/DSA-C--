#include <bits/stdc++.h>

struct Node
{
    Node *prev;
    int Data;
    Node *next;
};

Node *HEAD = new Node();

Node *generateNode(int x)
{
    // Below lines create a new node in the Heap
    // Can be only be accessed by the pointer
    // If pointer is lost, the data cannot be accessed anymore.
    // I prefer this method since it keeps memory stack free
    Node *newNode = new Node();
    newNode->Data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

    // Below lines create a new node in the stack
    // After the allocation the new node is deleted
    // ! Not prefered since uses stack to store and takes more memory
    // struct Node newNode;
    // newNode.Data = x;
    // newNode.next = NULL;
    // newNode.prev = NULL;
    // return &newNode;
}

void insertAtHead(int x)
{
    // Inserts a new node at head
    Node *newNode = generateNode(x);

    // If list is empty just create new node
    if (HEAD == NULL)
    {
        HEAD = newNode;
        return;
    }

    HEAD->prev = newNode;
    newNode->next = HEAD;
    HEAD = newNode;
}

void insertAtTail(int x)
{
    // Insert at end
    Node *newNode = generateNode(x);

    // If list is empty just create new node
    if (HEAD == NULL)
    {
        HEAD = newNode;
        return;
    }
    
    Node *pos = HEAD;
    // Traverse to end and set new node to to end
    while (pos->next != NULL)
        pos = pos->next;

    pos->next = newNode;
    newNode->prev = pos;
    pos = newNode;
}

void printForward()
{
    // Print in forward direction
    Node *pos = HEAD;
    while (pos != NULL)
    {
        std::cout << pos->Data << " -> ";
        pos = pos->next;
    }
    std::cout << "END" << std::endl;
}

void printBackward()
{
    // Revrse print
    Node *pos = HEAD;
    if (pos == NULL)
        return;
    while (pos->next != NULL)
        pos = pos->next;
    while (pos != NULL)
    {
        std::cout << pos->Data << " <- ";
        pos = pos->prev;
    }
    std::cout << "HEAD" << std::endl;
}

void printDL()
{
    printForward();
    printBackward();
}

int main()
{
    HEAD = NULL;
    insertAtHead(2);
    printDL();
    insertAtHead(1);
    printDL();
    insertAtHead(3);
    printDL();
    insertAtTail(5);
    printDL();
    return 0;
}
