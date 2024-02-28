#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int color, int delRow[], int delCol[], int iniColor)
{
    ans[row][col] = color;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == iniColor && ans[nRow][nCol] != color)
        {
            dfs(nRow, nCol, ans, image, color, delRow, delCol, iniColor);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> ans = image;
    int iniColor = image[sr][sc];
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr, sc, ans, image, color, delRow, delCol, iniColor);
    return ans;
}