#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<int>> &grid, int delRow[], int delCol[], int rowBase, int colBase, vector<pair<int, int>> &vec)
{
    visited[row][col] = true;
    vec.push_back({row - rowBase, col - colBase});
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
            !visited[nRow][nCol] && grid[nRow][nCol] == 1)
        {
            dfs(nRow, nCol, visited, grid, delRow, delCol, rowBase, colBase, vec);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vector<pair<int, int>> vec;
            if (!visited[i][j] && grid[i][j] == 1)
            {
                dfs(i, j, visited, grid, delRow, delCol, i, j, vec);
                st.insert(vec);
            }
        }
    }
    return st.size();
}