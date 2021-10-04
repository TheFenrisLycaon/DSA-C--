#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  map<int, bool> visited;
  map<int, vector<int>> adj;

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
  cout << v << " ";

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
  g.addEdge(2, 3);
  g.addEdge(2, 1);
  g.addEdge(3, 3);
  g.addEdge(3, 8);
  g.addEdge(3, 4);
  g.addEdge(4, 3);
  g.addEdge(4, 6);
  g.addEdge(4, 7);
  g.addEdge(5, 1);
  g.addEdge(6, 4);
  g.addEdge(7, 4);
  g.addEdge(8, 3);

  cout << "Following is Depth First Traversal"
          " (starting from vertex 0) \n";
  g.DFS(0);

  return 0;
}