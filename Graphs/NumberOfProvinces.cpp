#include <bits/stdc++.h>
using namespace std;
void dfs(int node, bool visited[], vector<vector<int>> &roads)
{
    visited[node] = true;
    for (int j = 0; j < roads.size(); j++)
    {
        if (roads[node][j] == 1 && !visited[j])
        {
            dfs(j, visited, roads);
        }
    }
}
int findNumOfProvinces(vector<vector<int>> &roads, int n)
{
    int count = 0;
    bool visited[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i, visited, roads);
        }
    }
    return count;
}