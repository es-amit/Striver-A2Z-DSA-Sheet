#include <bits/stdc++.h>
using namespace std;
bool dfs(int start, vector<int> &color, vector<vector<int>> &graph, int currCol)
{
    color[start] = currCol;
    for (auto it : graph[start])
    {
        if (color[it] == -1)
        {
            if (!dfs(it, color, graph, !currCol))
            {
                return false;
            }
        }
        else if (color[it] == color[start])
        {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> color(V, -1);
    int currColor = 0;
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, color, graph, currColor))
                return false;
        }
    }
    return true;
}