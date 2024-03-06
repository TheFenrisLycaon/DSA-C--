#include<bits/stdc++.h>
using namespace std;
//addEdge: add weights w with the edges
// dist vector contains weight of the edges
void addEdge(vector<vector<int>> &dist,int u,int v,int w)
{
    dist[u][v] = w;//each edge contains weight w 
}

// traverse the edges and find the minimum
// distance of every edge.
// finds the shortest path between all pairs of 
// vertices in the graph.
void warshall(vector<vector<int>>& dist, const int V)
{
    for(int i = 0; i < V; i++)
    {
        for(int j =0 ; j < V; j++)
        {
            for(int k = 0; k < V; k++)
            {
                if(dist[i][k] != INT_MAX and dist[k][j] != INT_MAX)
                {
                    //minimum distance will we overwritten for each and every edge.
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
int main()
{
    int V = 5;
    //create 2D vector with each weight distance as INT_MAX
    vector<vector<int>> dist(V,vector<int>(V, INT_MAX));
    //add edges along with their weights.
    addEdge(dist, 0, 1, 3);
    addEdge(dist, 0, 4, -4);
    addEdge(dist, 0, 2, 8);
    addEdge(dist, 1, 3, 1);
    addEdge(dist, 1, 4, 7);
    addEdge(dist, 2, 1, 4);
    addEdge(dist, 3, 0, 2);
    addEdge(dist, 3, 2, -5);
    addEdge(dist, 4, 3, 6);
    
    for (int i = 0; i < V; i++)
    {
        dist[i][i] = 0;// diagonals will always be 0
        //as the distance of a vertice with itself is 0.
    }
    // call for the calculation of minimum weights
    warshall(dist,V);
    //display all the vertices with shortest path to other vertices.
    cout<<"Shortest path from all vertices: "; 
    for(int i =0;i<V ;i++)
    {
        for(int j =0; j<V;j++)
        {
            cout<<i<<" , "<<j<<" : "<<dist[i][j]<< "\n";
        }
    }
    return 0;
}