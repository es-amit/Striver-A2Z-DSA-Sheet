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
int cutRod(int price[], int n)
{
    int length[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(length, price, n, n, dp);
}

int cutRodTabulation(int price[], int n)
{
    int length[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int j = 1; j < n + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                int pick = price[i - 1] + dp[i][j - length[i - 1]];
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
    return dp[n][n];
}