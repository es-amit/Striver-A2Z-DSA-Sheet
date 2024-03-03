#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        size.resize(n + 1, 1);
    }

    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges(V);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    int Mst = 0;
    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUParent(u) != ds.findUParent(v))
        {
            Mst += wt;
            ds.unionBySize(u, v);
        }
    }
    return Mst;
}