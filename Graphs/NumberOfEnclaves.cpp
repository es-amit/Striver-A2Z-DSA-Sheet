#include <bits/stdc++.h>
using namespace std;
int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int j = 0; j < m; j++)
    {
        if (!visited[0][j] && grid[0][j] == 1)
        {
            visited[0][j] = true;
            q.push({0, j});
        }

        if (!visited[n - 1][j] && grid[n - 1][j] == 1)
        {
            visited[n - 1][j] = true;
            q.push({n - 1, j});
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i][0] && grid[i][0] == 1)
        {
            visited[i][0] = true;
            q.push({i, 0});
        }

        if (!visited[i][m - 1] && grid[i][m - 1] == 1)
        {
            visited[i][m - 1] = true;
            q.push({i, m - 1});
        }
    }

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                q.push({nRow, nCol});
                visited[nRow][nCol] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}