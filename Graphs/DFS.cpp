#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &ans, bool visited[], int node)
{
    ans.push_back(node);
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (visited[it] == false)
        {
            dfs(adj, ans, visited, it);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    bool visited[V] = {false};
    vector<int> ans;
    dfs(adj, ans, visited, 0);
    return ans;
}