#include <bits/stdc++.h>
using namespace std;
void bfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid, int n, int m)
{
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        q.pop();
        // check for the neigbours
        for (int delRow = -1; delRow <= 1; delRow++)
        {
            for (int delCol = -1; delCol <= 1; delCol++)
            {
                int neighRow = row + delRow;
                int neighCol = col + delCol;
                if (neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m && grid[neighRow][neighCol] == '1' && !visited[neighRow][neighCol])
                {
                    visited[neighRow][neighCol] = true;
                    q.push(make_pair(neighRow, neighCol));
                }
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int islands = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                islands++;
                bfs(i, j, visited, grid, n, m);
            }
        }
    }
    return islands;
}