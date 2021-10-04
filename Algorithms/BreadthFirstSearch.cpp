#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int N, M;

    vector<int> *adj;
    public:
    Graph(int N);
    void BreadthFirstSearch(int v);
    void addEdge(int u, int v);
    
};

Graph::Graph(int N)
{
    this->N = N;
    adj = new vector<int>[N];
}

void Graph::BreadthFirstSearch(int v)    // Breadth First Search Algorithm
{
    bool *visited = new bool[N];
    for(int i = 0; i < N; i++)
    visited[i] = false;

    list<int> queue;

    visited[v] = true;
    queue.push_back(v);

    // list<int>::iterator i;
    while(!queue.empty())
    {
        v = queue.front();
        cout<<v<<" ";
        queue.pop_front();

        for(auto i:adj[v])
        {
            if(!visited[i])
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



int main() {
    
    cout<<"Enter N M"<<"\n";   // N= number of nodes , M = number od edges
    cout<<"Enter M lines , where each line has two nodes that form edges" <<"\n";

    int N, M;
    cin>>N>>M;

    Graph g(N);

    for(int i=0; i<M; i++)
    {
        int u, v;
        cin>>u>>v;

        g.addEdge(u, v);
    }

    cout<<"Enter the vertex from which traversal has to be started"<<"\n";
    int s; cin>>s;

    cout<< "Following is Breadth First Traversal (starting from vertex "<<s<<" )"<<"\n";
    g.BreadthFirstSearch(s); 

    
    return 0;
}
