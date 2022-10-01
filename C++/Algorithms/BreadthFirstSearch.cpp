#include <bits/stdc++.h>

class Graph
{
    int N, M;

    std ::vector<int> *adj;

public:
    Graph(int N);
    void BreadthFirstSearch(int v);
    void addEdge(int u, int v);
};

Graph::Graph(int N)
{
    this->N = N;
    adj = new std ::vector<int>[N];
}

void Graph::BreadthFirstSearch(int v) // Breadth First Search Algorithm
{
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    std ::list<int> queue;

    visited[v] = true;
    queue.push_back(v);

    // std :: list<int>::iterator i;
    while (!queue.empty())
    {
        v = queue.front();
        std ::cout << v << " ";
        queue.pop_front();

        for (auto i : adj[v])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

int main()
{

    std ::cout << "Enter N M"
               << std ::endl; // N= number of nodes , M = number od edges
    std ::cout << "Enter M lines , where each line has two nodes that form edges"
               << std ::endl;

    int N, M;
    std ::cin >> N >> M;

    Graph g(N);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        std ::cin >> u >> v;

        g.addEdge(u, v);
    }

    std ::cout << "Enter the vertex from which traversal has to be started"
               << std ::endl;
    int s;
    std ::cin >> s;

    std ::cout << "Following is Breadth First Traversal (starting from vertex " << s << " )"
               << std ::endl;
    g.BreadthFirstSearch(s);

    return 0;
}
