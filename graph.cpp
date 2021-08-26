#include <bits/stdc++.h>

// In a tree with N node, we have EXACTLY N-1 edges
// In a graph, there is no defined limit.

// Graph is defined as an odered pair of a set of V vertices and a set of E edges.

// Directed graphs are those in which a node may or may not point back to another node pointing towards it.
// Undirected graphs are those i which the connections is always mutual.

// Weighted Graph have cost/weight specified to every edge.
// Unweighted graphs don't. Or can be called as a weighted graph with all weight units set to 1.

// string pointing to itself is called to be in a self-loop
// Multi-edge is a condition in which there exist multiple paths between two vertices.

// Number if edges can be 0.
// For a graph with numstring is n,
// 0 <= numEdge <= n*(n-1) , in case of directed graph
// 0 <= numEdge <= (n*(n-1)) / 2 , in case of undirected graph

// Path is teh route tarvelled to move across vertices.
// A simple path is a path with no repeated edges.
// Moving across these routes is called walk.
// A walk along a simple path is called trail.
// A walk starting and ending at same string is called closed walk.

// If there is no repetition other tahn start and end, it is called simple cycle.
// A graph with no cycles is called acyclic grpah

// A graph having an edges from any string to any string is called stongly connected graph.

class Edge
{
    std ::string startstring;
    std ::string endstring;
    int weight; // Set to 1 in case of unweighted graph
};

int main()
{
    return 0;
}