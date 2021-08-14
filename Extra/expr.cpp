#include <bits/stdc++.h>
// using namespace std;

std ::stack<char> mem;

int evalPostFix(std::string expr)
{
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            int a = (int)mem.top();
            mem.pop();
            int b = (int)mem.top();
            mem.pop();

            switch (expr[i])
            {
            case '+':
                mem.push(b + a);
                break;
            case '-':
                mem.push(b - a);
                break;
            case '*':
                mem.push(a * b);
                break;
            case '/':
                mem.push(b / a);
                break;
            }
        }

        else
        {
            mem.push(expr[i] - '0');
        }
    }
    return (int)mem.top();
}

int evalPreFix(std::string expr)
{
    for (int i = expr.length(); i >= 0; i--)
    {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            int b = (int)mem.top();
            mem.pop();
            int a = (int)mem.top();
            mem.pop();

            switch (expr[i])
            {
            case '+':
                mem.push(b + a);
                break;
            case '-':
                mem.push(b - a);
                break;
            case '*':
                mem.push(a * b);
                break;
            case '/':
                mem.push(b / a);
                break;
            }
        }

        else
        {
            mem.push(expr[i] - '0');
        }
    }
    return (int)mem.top();
}

int main()
{
    std::string k = "23*54*+9-";
    std::string l = "-+*23*549";
    std ::cout << evalPostFix(k) << std::endl;
    std ::cout << evalPreFix(l) << std::endl;
    return 0;
}
