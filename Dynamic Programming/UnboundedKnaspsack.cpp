#include <bits/stdc++.h>
using namespace std;
int solve(int wt[], int val[], int n, int w, vector<vector<int>> &dp)
{
    if (w == 0)
        return 0;
    if (n == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n - 1] <= w)
    {
        int pick = val[n - 1] + solve(wt, val, n, w - wt[n - 1], dp);
        int notpick = solve(wt, val, n - 1, w, dp);
        return dp[n][w] = max(pick, notpick);
    }
    else
    {
        int notpick = solve(wt, val, n - 1, w, dp);
        return dp[n][w] = notpick;
    }
}
int knapSackMemo(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
    return solve(wt, val, N, W, dp);
}

int knapSackTabulation(int n, int W, int val[], int wt[])
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int j = 1; j < W + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                int pick = val[i - 1] + dp[i][j - wt[i - 1]];
                int notpick = dp[i - 1][j];
                dp[i][j] = max(pick, notpick);
            }
            else
            {
                int notpick = dp[i - 1][j];
                dp[i][j] = notpick;
            }
        }
    }
    return dp[n][W];
}