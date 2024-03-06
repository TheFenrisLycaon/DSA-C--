#include <set>
#include <map>
#include <string>
#include <iostream>
int main()
{
  unsigned int logins = 50; 
#ifndef ORIGINAL
  std::cin >> logins;
#endif
  std::map<char, std::set<char>> previous;
  while (logins--)
  {
    std::string line;
    std::cin >> line;
    previous[line[0]];
    for (unsigned int i = 1; i < line.size(); i++)
      previous[line[i]].insert(line[i - 1]);
  }
  std::string result;
  while (!previous.empty())
  {
    auto emptySet = previous.begin();
    while (emptySet != previous.end() && !emptySet->second.empty())
      emptySet++;
    if (emptySet == previous.end())
    {
      result = "SMTH WRONG"; 
      break;
    }
    auto current = emptySet->first;
    result += current;
    previous.erase(current);
    for (auto& p : previous)
      p.second.erase(current);
  }
  std::cout << result << std::endl;
  return 0;
} 