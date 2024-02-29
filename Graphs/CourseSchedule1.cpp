#include <bits/stdc++.h>
using namespace std;
bool canFinish(int V, vector<vector<int>> &prerequisites)
{
    vector<int> adj[V];
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        // node is in your topo sort
        // so please remove it from the indegree

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    if (count == V)
        return true;
    return false;
}