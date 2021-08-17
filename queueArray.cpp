#include <bits/stdc++.h>
#define MAX 10

class Queue
{
    // ! This method of implementing queue is bad since we cannot reuse the position whixh was once filled.
    // Thus we should use circular arrays
public:
    int arr[MAX];
    int rear = -1;
    int front = -1;

    bool isEmpty()
    {
        return (front == -1 && rear == -1) ? true : false;
    }

    bool isFull()
    {
        return (rear == MAX - 1) ? true : false;
    }

    void enqueue(int x)
    {
        if (isFull())
            return;
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
            rear++;

        arr[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front++;
    }

    void print()
    {
        if (rear != -1)
            for (int i = front; i <= rear; i++)
                std::cout << arr[i];
        else
            std::cout << "EMPTY QUEUE";

        std::cout << std::endl;
    }

    int peek()
    {
        return arr[front];
    }
};

class QueueF
{

public:
    int arr[MAX];
    int rear = -1;
    int front = -1;

    bool isEmpty()
    {
        return (front == -1 && rear == -1) ? true : false;
    }

    void enqueue(int x)
    {
        if ((rear + 1) % MAX == front)
            return;
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
            rear += (rear + 1) % MAX;

        arr[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front += (front + 1) % MAX;
    }

    void print()
    {
        if (rear != -1)
            for (int i = front; i <= rear; i++)
                std::cout << arr[i];
        else
            std::cout << "EMPTY QUEUE";

        std::cout << std::endl;
    }

    int peek()
    {
        return arr[front];
    }
};

int main()
{
    QueueF q;
    q.print();
    q.enqueue(7);
    q.print();
    q.enqueue(8);
    std::cout << "PEEK " << q.peek() << std::endl;
    q.print();
    q.dequeue();
    q.print();
    std::cout << "PEEK " << q.peek() << std::endl;
    return 0;
}