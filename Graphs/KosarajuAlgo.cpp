#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj, st);
        }
    }
    st.push(node);
}
void dfs3(int node, vector<bool> &vis, vector<int> adjT[])
{
    vis[node] = true;
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs3(it, vis, adjT);
        }
    }
}
int kosaraju(int V, vector<vector<int>> &adj)
{
    // step-1
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, st);
        }
    }

    // step-2
    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    // step-3
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            dfs3(node, visited, adjT);
            scc++;
        }
    }
    return scc;
}