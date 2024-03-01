#include <bits/stdc++.h>

using namespace std;
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // adjacency list bnai
    vector<int> adj[N];
    for (auto it : edges)
    {
        adj[it[1]].push_back(it[0]);
        adj[it[0]].push_back(it[1]);
    }

    // yha se algo start hai

    vector<int> dist(N, 1e9);
    // BFS Implementation.
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
        {
            dist[i] = -1;
        }
    }
    return dist;
}