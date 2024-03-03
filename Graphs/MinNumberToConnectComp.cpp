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
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);
        int cntExtra = 0;
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUParent(u) == ds.findUParent(v))
            {
                cntExtra++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                cntC++;
        }
        int ans = cntC - 1;

        if (cntExtra >= ans)
        {
            return ans;
        }
        return -1;
    }
};