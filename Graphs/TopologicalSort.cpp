#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited, st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}