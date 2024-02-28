#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], bool visited[])
{
    visited[src] = true;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto adjacentNode : adj[node])
        {
            if (!visited[adjacentNode])
            {
                visited[adjacentNode] = true;
                q.push({adjacentNode, node});
            }
            else if (parent != adjacentNode)
            {
                return true;
            }
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
            if (detect(i, adj, visited) == true)
            {
                return true;
            }
        }
    }
    return false;
}