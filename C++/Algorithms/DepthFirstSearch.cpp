#include <bits/stdc++.h>

class Graph
{
public:
  std ::map<int, bool> visited;
  std ::map<int, std ::vector<int>> adj;

  void addEdge(int v, int w);

  void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}

void Graph::DFS(int v)
{
  visited[v] = true;
  std ::cout << v << " ";

  for (auto it : adj[v])
  {
    if (!visited[it])
      DFS(it);
  }
}

int main()
{
  Graph g;
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(1, 5);
  g.addEdge(2, 0);

  std ::cout << "Following is Depth First Traversal"
                " (starting from vertex 0) \n";
  g.DFS(0);

  return 0;
}