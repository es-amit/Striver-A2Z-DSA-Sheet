#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> &triangle, int &m, int &n, vector<vector<int>> &dp)
{
    if (i == m - 1)
        return triangle[m - 1][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + solve(i + 1, j, triangle, m, n, dp);
    int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, m, n, dp);
    return dp[i][j] = min(down, diagonal);
}
int minimumTotalMemo(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, triangle, m, n, dp);
}
int minimumTotalTabulation(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int j = 0; j < n; j++)
    {
        dp[m - 1][j] = triangle[m - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}