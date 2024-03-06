#include <malloc.h>
#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node ND;

ND *head;

ND *NewNode()
{
    return (ND *)malloc(sizeof(ND));
}

void createNode(int item)
{
    ND *ptr;
    ND *new1 = NewNode();
    new1->data = item;
    new1->next = NULL;

    if (head == NULL)
        head = new1;
    else //insert at last
    {
        ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new1;
    }
}

void display() //traversal
{
    ND *ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
}
void insertatfirst(int item)
{
    ND *new1 = NewNode();
    new1->data = item;
    new1->next = head;
    head = new1;
}

int DeleteAtFirst()
{
    int item = head->data;
    head = head->next;
    return item;
}

int DeletionAtLast()
{
    ND *ptr = head;
    ND *prev;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    int item = ptr->data;
    prev->next = NULL;
    return item;
}

int lengthLL()
{
    ND *ptr = head;
    int res = 0;
    while (ptr != NULL)
    {
        res++;
        ptr = ptr->next;
    }
    return res;
}

void deleteMultiple(int num)
{
    for (int i = 0; i < num; i++)
        DeletionAtLast();
    display();
}

void deleteAll()
{
    ND *ptr = head;
    while (ptr != NULL)
    {
        free(ptr);
        ptr = ptr->next;
    }
}

int main()
{
    head = NULL;
    createNode(9);
    createNode(6);
    createNode(4);
    createNode(0);
    createNode(7);
    createNode(5);
    display();
    int num;
    printf("\nEnter num of nodes to delete::\t");
    scanf("%d", &num);
    int length = lengthLL();
    printf("%d", length);
    if (num > length)
        printf("\n\nEnter smaller number. Index out of range!\n\n");
    else if (num == length)
    {
        deleteAll();
        printf("All nodes deleted exiting!");
        exit(0);
    }
    else
        deleteMultiple(num);

    display();

    //insertatfirst(45);

    //display();

    return 0;
}
