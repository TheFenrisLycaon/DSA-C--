#include <bits/stdc++.h>

class LinkedList
{
public:
  struct Node
  {
    Node *next;
    std ::string val;
    Node(std ::string a) : next(NULL), val(a) {}
  };

  Node *head;

  LinkedList() : head(NULL) {}

  void insert(std::string data, int n)
  {
    Node *newNode = new Node(data);
    if (n == 0)
    {
      newNode->next = head;
      head = newNode;
      return;
    }
    Node *pos = head;
    if (n == -1)
    {
      while (pos->next != NULL)
        pos = pos->next;
      pos->next = newNode;
      return;
    }
  }

  std::string concatList()
  {
    std ::string str = "";
    Node *ptr = head;

    while (ptr)
    {
      str += ptr->val;
      ptr = ptr->next;
    }
    
    return str;
  }

  bool isPalindrome()
  {
    std ::string concatinatedStr = concatList();
    int n = concatinatedStr.length();
    for (int i = 0; i < n / 2; i++)
      if (concatinatedStr[i] != concatinatedStr[n - i - 1])
        return false;
    return true;
  }

};

int main()
{
  LinkedList *list = new LinkedList();

  std::string temp;

  getline(std::cin, temp);
  list->insert(temp, 0);

  while (!temp.empty())
  {
    getline(std::cin, temp);
    list->insert(temp, -1);
  }

  std::cout << "String " << list->concatList() << " ";

  (list->isPalindrome()) ? std::cout << "forms a palindrome" : std::cout << "doesn't form a palindrome";

  std ::cout << std::endl;

  return 0;
}