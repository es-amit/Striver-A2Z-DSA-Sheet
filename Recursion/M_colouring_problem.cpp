#include <bits/stdc++.h>
using namespace std;
bool isSafe(bool graph[101][101], vector<int> &colors, int node, int c, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (i != node && graph[node][i] && colors[i] == c)
        {
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101], vector<int> &colors, int node, int m, int n)
{
    if (node == n)
    {
        return true;
    }

    for (int i = 1; i <= m; ++i)
    {
        if (isSafe(graph, colors, node, i, n))
        {
            colors[node] = i;
            if (solve(graph, colors, node + 1, m, n))
            {
                return true;
            }
            colors[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> colors(n, 0);
    return solve(graph, colors, 0, m, n);
}