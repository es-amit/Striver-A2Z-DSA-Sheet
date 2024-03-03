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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        DisjointSet ds(n * m);
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<int> ans;
        int islands = 0;
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if (visited[row][col])
            {
                ans.push_back(islands);
                continue;
            }
            visited[row][col] = true;
            islands++;
            for (int dir = 0; dir < 4; dir++)
            {
                int nRow = row + drow[dir];
                int nCol = col + dcol[dir];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol])
                {
                    int node = (row * m) + col;
                    int adjNode = (nRow * m) + nCol;
                    if (ds.findUParent(node) != ds.findUParent(adjNode))
                    {
                        islands--;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
            ans.push_back(islands);
        }
        return ans;
    }
};