#include <bits/stdc++.h>

struct Node
{
    int value;
    Node *next;
};

struct Node *last = NULL;

struct Node *insertEmpty(struct Node *last, int value)
{
    // Inserting to an empty list
    if (last != NULL)
        return last;

    Node *temp = new Node();
    temp->value = value;
    last = temp;
    temp->next = last;

    return last;
}

struct Node *insertStart(struct Node *last, int value)
{
    // Insert at start
    if (last == NULL)
        return insertEmpty(last, value);

    Node *temp = new Node();
    temp->value = value;
    temp->next = last->next;
    last->next = temp;

    return last;
}

struct Node *insertLast(struct Node *last, int value)
{
    // Insert at end
    if (last == NULL)
        return insertEmpty(last, value);

    Node *temp = new Node();
    temp->value = value;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

struct Node *insertAfter(struct Node *last, int value, int item)
{
    // Insert at a certain value
    if (last == NULL)
        return NULL;

    struct Node *temp, *p;

    p = last->next;
    do
    {
        if (p->value == item)
        {
            temp = new Node();
            temp->value = value;
            temp->next = p->next;
            p->next = temp;
            if (p == last)
                last = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);

    std::cout << item << " not present in the list." << std::endl;

    return last;
}

void traverse(struct Node *last)
{
    // Print list

    Node *p;
    if (last == NULL)
        return;

    p = last->next;

    do
    {
        std::cout << p->value << " ";
        p = p->next;
    } while (p != last->next);
}

int main()
{
    int size, value;
    last = insertEmpty(last, 2);
    last = insertStart(last, 4);
    last = insertStart(last, 6);
    last = insertLast(last, 8);
    last = insertLast(last, 10);
    last = insertAfter(last, 11, 8);
    traverse(last);
    std::cout << std::endl;
    return 0;
}