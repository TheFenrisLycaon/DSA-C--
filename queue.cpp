#include <bits/stdc++.h>
#define MAX 10

int size = 0;

struct stack
{
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s)
{
    s->top = -1;
}

int isfull(st *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty(st *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(st *s, int newitem)
{
    if (isfull(s))
    {
        std ::cout << "STACK FULL";
    }
    else
    {
        s->top++;
        s->items[s->top] = newitem;
    }
    size++;
}

void pop(st *s)
{
    if (isempty(s))
    {
        std ::cout << "\n STACK EMPTY \n";
    }
    else
    {
        std ::cout << "Item popped= " << s->items[s->top];
        s->top--;
    }
    size--;
    std ::cout << std ::endl;
}

void printStack(st *s)
{
    printf("Stack: ");
    for (int i = 0; i < size; i++)
    {
        std ::cout << s->items[i] << " ";
    }
    std ::cout << std ::endl;
}

int main()
{
    int ch;
    st *s = (st *)malloc(sizeof(st));

    createEmptyStack(s);

    push(s, 1);
    printStack(s);
    push(s, 2);
    printStack(s);
    push(s, 3);
    printStack(s);
    push(s, 4);
    printStack(s);
    pop(s);
    printStack(s);
    return 0;
}