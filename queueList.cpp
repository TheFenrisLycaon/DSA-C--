#include <bits/stdc++.h>

struct Node
{
    int value;
    Node *next;
};

struct Node *FRONT = NULL;
struct Node *REAR = NULL;

void enqueue(int x)
{
    Node *newNode = new Node();
    newNode->value = x;
    newNode->next = NULL;

    if (FRONT == NULL && REAR == NULL)
    {
        FRONT = REAR = newNode;
        return;
    }
    REAR->next = newNode;
    REAR = newNode;
}

void dequeue()
{
    Node *newNode = FRONT;

    if (FRONT == NULL)
        return;
    if (FRONT == REAR)
        FRONT = REAR = NULL;
    else
        FRONT = FRONT->next;

    free(newNode);
}

bool isEmpty()
{
    return (FRONT == NULL && REAR == NULL) ? true : false;
}

int peek()
{
    if (FRONT != NULL)
        return FRONT->value;
    else
        return -1;
}

void print()
{
    if (FRONT == NULL)
        return;
    else
    {
        Node *pos = FRONT;
        while (pos != NULL)
        {
            std ::cout << pos->value << "\t";
            pos = pos->next;
        }
        std::cout << std::endl;
    }
}

int main()
{
    enqueue(1);
    print();
    enqueue(2);
    print();
    enqueue(3);
    print();
    enqueue(4);
    print();
    dequeue();
    print();
    dequeue();
    print();
    enqueue(1);
    print();
    enqueue(2);
    print();
    enqueue(3);
    print();
    enqueue(4);
    print();
    return 0;
}
