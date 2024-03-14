#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}
int matrixMultiplicationMemo(int N, int arr[])
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return solve(arr, 1, N - 1, dp);
}

int matrixMultiplicationTabulation(int N, int arr[])
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <= N - 1; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                mini = min(steps, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}