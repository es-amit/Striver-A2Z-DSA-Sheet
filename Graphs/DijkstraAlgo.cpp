#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<p, vector<p>, greater<p>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0, S});
    dist[S] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int edgeWeight = it[1];
            int adjNode = it[0];
            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}