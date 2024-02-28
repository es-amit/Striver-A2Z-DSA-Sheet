#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int parent, vector<int> adj[], bool visited[])
{
    visited[node] = true;
    for (auto adjacentNode : adj[node])
    {
        if (!visited[adjacentNode])
        {
            if (dfs(adjacentNode, node, adj, visited) == true)
                return true;
        }
        else if (adjacentNode != parent)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    bool visited[V] = {false};
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, visited) == true)
            {
                return true;
            }
        }
    }
    return false;
}