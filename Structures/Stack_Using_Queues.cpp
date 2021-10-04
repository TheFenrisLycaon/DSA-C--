#include <bits/stdc++.h>

class Stack
{

public:
  std ::queue<int> q1, q2;

  void push(int x)
  {
    if (!q1.empty())
      q1.push(x);
    else
      q2.push(x);
  }

  void pop()
  {
    if (q1.empty())
    {
      while (!q2.empty())
      {
        int front = q2.front();
        q2.pop();

        if (q2.empty())
          break;

        q1.push(front);
      }
    }
    else
    {
      while (!q1.empty())
      {
        int front = q1.front();
        q1.pop();

        if (q1.empty())
          break;

        q2.push(front);
      }
    }
  }

  bool empty()
  {
    return q1.empty() and q2.empty();
  }

  int top()
  {
    if (q1.empty())
    {
      while (!q2.empty())
      {
        int front = q2.front();
        q2.pop();

        q1.push(front);

        if (q2.empty())
          return front;
      }
    }
    else
    {
      while (!q1.empty())
      {
        int front = q1.front();

        q2.push(front);
        q1.pop();

        if (q1.empty())
          return front;
      }
    }
  }
};

int main()
{

  Stack stack;
  std::cout << "Empty Stack Status::\t" << stack.empty() << std::endl;
  stack.push(5);

  std::cout << "Empty Stack Status::\t" << stack.empty() << std::endl;
  stack.push(4);
  stack.push(3);
  stack.push(2);

  std::cout << "Top Element::\t" << stack.top() << std::endl;
  stack.pop();

  std::cout << "Top Element::\t" << stack.top() << std::endl;

  while (!stack.empty())
  {
    std::cout << stack.top() << std::endl;
    stack.pop();
  }

  return 0;
}
