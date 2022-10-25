#include <bits/stdc++.h>
#include <cctype>
using namespace std;
class Stack
{
  char *arr;
  int top;

public:
  Stack(int n)
  {
    top = -1;
    arr = new char(n);
  }
  bool isEmpty()
  {
    if (top == -1)
      return true;
    return false;
  }
  void push(char ch)
  {
    top += 1;
    arr[top] = ch;
  }

  char pop()
  {
    if (!isEmpty())
    {
      char ch = arr[top];
      top -= 1;
      return ch;
    }
    return -1;
  }
};

int order(char ch)
{
  if (ch == '(')
    return 1;
  else if (ch == '+' || ch == '-')
    return 2;
  else if (ch == '*' || ch == '/')
    return 3;
  else if (ch == '^')
    return 4;
  else
    return -1;
}

string infix_to_postfix(string s)
{
  int i;
  int len = s.length();
  char ch;
  string ans;
  Stack array(len);
  for (i = 0; i < s.length(); i++)
  {
    if (isalpha(s[i]) || isdigit(s[i]))
    {
      ans += s[i];
    }
    else
    {

      if (array.isEmpty())
      {
        array.push(s[i]);
      }
      else
      {

        if (s[i] == '(')
        {
          array.push(s[i]);
        }
        else
        {
          ch = array.pop();

          if (s[i] == ')')
          {
            while (ch != '(')
            {
              ans += ch;
              ch = array.pop();
            }
          }

          else if (order(ch) < order(s[i]))
          {
            array.push(ch);
            array.push(s[i]);
          }
          else
          {
            ans += ch;
            ch = s[i];
            char ch2 = array.pop();
            while (order(ch2) >= order(ch))
            {
              ans += ch2;
              ch2 = array.pop();
            }
            array.push(ch2);
            array.push(ch);
          }
        }
      }
    }
  }

  while (!array.isEmpty())
  {
    ch = array.pop();
    ans += ch;
  }

  return ans;
}

int main()
{

  string s = "";
  cout<<"Enter the expression : ";
  cin>>s;
  string ans;
  ans = infix_to_postfix(s);
  cout << ans;
}