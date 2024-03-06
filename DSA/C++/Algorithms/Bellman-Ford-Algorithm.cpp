// Bellman Ford Algorithm Used for finding Shortest Path In graph where there is a Negative weighted edges

#include <bits/stdc++.h>

int main()
{
    int nodes, edges;
    std ::cin >> nodes >> edges;

    // grapg generation
    vector<vector<int>> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, wt;
        std ::cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int src;
    std ::cin >> src;

    int dist[nodes];
    for (int i = 0; i < nodes; i++)
        dist[i] = INT_MAX;

    // set 0 as source
    // so it's distance = 0
    dist[src] = 0;

    // nodes-1 time relaxing
    for (int i = 0; i < nodes - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it[0]] != INT_MAX && dist[it[0]] + it[2] < dist[it[1]])
            {
                dist[it[1]] = dist[it[0]] + it[2];
            }
        }
    }

    bool neg_cycle = false;
    // last relaxing for find is there negative cycle ?
    //  if yes then nth time relaxing dist value sholud want to update
    for (auto it : edges)
    {
        if (dist[it[0]] != INT_MAX && dist[it[0]] + it[2] < dist[it[1]])
        {
            neg_cycle = true;
            break;
        }
    }

    if (neg_cycle)
    {
        std ::cout << "Negative Cycle so not shortest path valid";
    }
    else
    {
        for (int i = 0; i < nodes; i++)
        {
            std ::cout << i << " " << dist[i] << "\nodes";
        }
    }
    return 0;
}