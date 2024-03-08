#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &coins, int n, int amount, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][amount] != -1)
        return dp[n][amount];

    if (coins[n - 1] <= amount)
    {
        int pick = solve(coins, n, amount - coins[n - 1], dp);
        int notpick = solve(coins, n - 1, amount, dp);
        return dp[n][amount] = pick + notpick;
    }
    else
    {
        int notpick = solve(coins, n - 1, amount, dp);
        return dp[n][amount] = notpick;
    }
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    return solve(coins, n, amount, dp);
}

int changeTabulation(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int j = 1; j < amount + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                int pick = dp[i][j - coins[i - 1]];
                int notpick = dp[i - 1][j];
                dp[i][j] = pick + notpick;
            }
            else
            {
                int notpick = dp[i - 1][j];
                dp[i][j] = notpick;
            }
        }
    }
    return dp[n][amount];
}