#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<char>> &board, vector<vector<bool>> &visited, int delRow[], int delCol[])
{
    visited[row][col] = true;
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && board[nRow][nCol] == 'O')
        {
            dfs(nRow, nCol, board, visited, delRow, delCol);
        }
    }
}
void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int j = 0; j < m; j++)
    {
        if (!visited[0][j] && board[0][j] == 'O')
        {
            dfs(0, j, board, visited, delRow, delCol);
        }

        if (!visited[n - 1][j] && board[n - 1][j] == 'O')
        {
            dfs(n - 1, j, board, visited, delRow, delCol);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i][0] && board[i][0] == 'O')
        {
            dfs(i, 0, board, visited, delRow, delCol);
        }

        if (!visited[i][m - 1] && board[i][m - 1] == 'O')
        {
            dfs(i, m - 1, board, visited, delRow, delCol);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}