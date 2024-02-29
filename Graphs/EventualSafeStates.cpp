#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited, vector<int> &check)
{
    visited[node] = 1;
    pathVisited[node] = 1;
    check[node] = 0;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (dfs(it, adj, visited, pathVisited, check) == true)
            {
                return true;
            }
        }
        else if (pathVisited[it] == 1)
        {
            return true;
        }
    }
    check[node] = 1;
    pathVisited[node] = 0;

    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    vector<int> check(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited, pathVisited, check);
        }
    }
    vector<int> safeNode;
    for (int i = 0; i < V; i++)
    {
        if (check[i] == 1)
        {
            safeNode.push_back(i);
        }
    }
    return safeNode;
}