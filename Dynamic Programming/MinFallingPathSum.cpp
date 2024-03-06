#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>> &matrix, int &n, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
        return 1e8;
    if (i == 0)
        return matrix[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = matrix[i][j] + solve(i - 1, j, matrix, n, dp);
    int ld = matrix[i][j] + solve(i - 1, j - 1, matrix, n, dp);
    int rd = matrix[i][j] + solve(i - 1, j + 1, matrix, n, dp);
    return dp[i][j] = min(up, min(ld, rd));
}
int minFallingPathSumMemo(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int mini = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        mini = min(mini, solve(m - 1, j, matrix, n, dp));
    }
    return mini;
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
            {
                leftDiagonal += dp[i - 1][j - 1];
            }
            else
            {
                leftDiagonal += 1e8;
            }

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
            {
                rightDiagonal += dp[i - 1][j + 1];
            }
            else
            {
                rightDiagonal += 1e8;
            }

            dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        maxi = min(maxi, dp[n - 1][j]);
    }

    return maxi;
}