#include <bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{

    if (source.first == destination.first && source.second == destination.second)
    {
        return 0;
    }
    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    q.push({0, {source.first, source.second}});
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};
    dist[source.first][source.second] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && dis + 1 < dist[nRow][nCol])
            {
                dist[nRow][nCol] = dis + 1;
                if (nRow == destination.first && nCol == destination.second)
                {
                    return dis + 1;
                }
                q.push({dis + 1, {nRow, nCol}});
            }
        }
    }

    return -1;
}