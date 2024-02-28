#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    vector<vector<int>> ans = grid;
    int n = grid.size();
    int m = grid[0].size();
    int fresh = 0;
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == 2)
            {
                q.push(make_pair(make_pair(i, j), 0));
            }
            else if (ans[i][j] == 1)
            {
                fresh++;
            }
        }
    }
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    int time = 0;
    int cnt = 0;
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(time, t);
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && ans[nRow][nCol] != 2)
            {
                ans[nRow][nCol] = 2;
                q.push(make_pair(make_pair(nRow, nCol), t + 1));
                cnt++;
            }
        }
    }
    if (cnt == fresh)
    {
        return time;
    }
    return -1;
}