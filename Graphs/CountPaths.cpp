#include <bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>> &roads)
{
    vector<pair<int, long long>> adj[n];
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n, LONG_MAX);
    vector<long long> ways(n, 0);
    ways[0] = 1;
    dist[0] = 0;
    int mod = (int)(1e9 + 7);
    pq.push({0, 0});
    while (!pq.empty())
    {
        int node = pq.top().second;
        long long dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;
            if (edW + dis < dist[adjNode])
            {
                dist[adjNode] = edW + dis;
                pq.push({dis + edW, adjNode});
                ways[adjNode] = ways[node];
            }
            else if (edW + dis == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1] % mod;
}