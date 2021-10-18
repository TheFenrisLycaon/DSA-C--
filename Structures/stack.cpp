// C++ Program to Implement stack using Class Templates

// Including input output libraries
#include <iostream>
// Header File including all string functions
#include <string>

using namespace std;

// Taking size of stack as 10
#define SIZE 5

template <class T>
class Stack
{
    // Pubic access modifier
public:
    // Empty constructor
    Stack();

    void push(T k);

    T pop();

    bool isFull();

    bool isEmpty();

private:
    // Taking data member top
    int top;

    // Initialising stack(array) of given size
    T st[SIZE];
};

template <class T>
Stack<T>::Stack() { top = -1; }

template <class T>
void Stack<T>::push(T k)
{

    // Checking whether stack is completely filled
    if (isFull())
    {
        // Display message when no elements can be pushed
        // into it
        cout << "Stack is full\n";
    }

    // Inserted element
    cout << "Inserted element " << k << endl;

    // Incrementing the top by unity as element
    // is to be inserted
    top = top + 1;

    // Now, adding element to stack
    st[top] = k;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

template <class T>
bool Stack<T>::isFull()
{
    // Till top in inside the stack
    if (top == (SIZE - 1))
        return 1;
    else

        // As top can not exceeds th size
        return 0;
}

// Method 10
template <class T>
T Stack<T>::pop()
{
    // Initialising a variable to store popped element
    T popped_element = st[top];

    // Decreasing the top as
    // element is getting out from the stack
    top--;

    // Returning the element/s that is/are popped
    return popped_element;
}

int main()
{
    Stack<int> integer_stack;
    Stack<string> string_stack;

    integer_stack.push(2);
    integer_stack.push(54);
    integer_stack.push(255);

    string_stack.push("Hello");
    string_stack.push("I am");
    string_stack.push("Seema");

    cout << integer_stack.pop() << " is removed from stack"
         << endl;

    cout << string_stack.pop() << " is removed from stack "
         << endl;

    return 0;
}
