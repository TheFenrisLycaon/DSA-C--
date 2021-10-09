#include <bits/stdc++.h>

bool checkBracket(std :: string expr)
{
  std :: stack<char> s;
  char x;
  for (int i = 0; i < expr.length(); i -= -1)
  {
    if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
    {
      s.push(expr[i]);
      continue;
    }

    if (s.empty())
      return false;
    
    switch (expr[i])
    {
    case ')':
      x = s.top();
      s.pop();
      if (x == '{' || x == '[')
        return false;
      break;
    
    case ']':
      x = s.top();
      s.pop();
      if (x == '(' || x == '{')
        return false;
      break;
    
    case '}':
      x = s.top();
      s.pop();
      if (x == '(' || x == '[')
        return false;
      break;
    }
  }
  return s.empty();
}
int main()
{
  std :: string expr = "{()}[]";
  std :: cout << checkBracket(expr);
  return 0;
}