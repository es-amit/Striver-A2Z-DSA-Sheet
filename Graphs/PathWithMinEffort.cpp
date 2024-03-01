#include <bits/stdc++.h>
using namespace std;
int MinimumEffort(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    pq.push({0, {0, 0}});
    dist[0][0] = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if (row == n - 1 && col == m - 1)
            return diff;
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + drow[i];
            int nCol = col + dcol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m)
            {
                int newEffort = max(abs(heights[nRow][nCol] - heights[row][col]), diff);
                if (newEffort < dist[nRow][nCol])
                {
                    dist[nRow][nCol] = newEffort;
                    pq.push({newEffort, {nRow, nCol}});
                }
            }
        }
    }
    return 0;
}