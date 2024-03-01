#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    // Dijkstra algo + Memoization Bactrack
    int src = 1;
    int dest = n;
    // create adjacency list
    vector<pair<int, int>> adj[n + 1];

    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int wt = i[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i; // self loop
    }

    dist[src] = 0;
    // distance, node
    pq.push({0, src});

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto i : adj[node])
        {
            int adjNode = i.first;
            int weight = i.second;

            if (distance + weight < dist[adjNode])
            {
                dist[adjNode] = distance + weight;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if (dist[dest] == 1e9)
    {
        return {-1};
    }

    vector<int> path;
    int node = dest;

    while (parent[node] != node) // not self loop
    {
        path.push_back(node);
        node = parent[node];
    }

    // pushing 1st element manually
    path.push_back(src);

    reverse(path.begin(), path.end());

    return path;
}