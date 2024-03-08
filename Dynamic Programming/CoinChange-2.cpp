#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &coins, int n, int amount, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 0;
    if (n == 0)
        return INT_MAX - 1;
    if (dp[n][amount] != -1)
        return dp[n][amount];

    if (coins[n - 1] <= amount)
    {
        int pick = 1 + solve(coins, n, amount - coins[n - 1], dp);
        int notpick = solve(coins, n - 1, amount, dp);
        return dp[n][amount] = min(pick, notpick);
    }
    else
    {
        int notpick = solve(coins, n - 1, amount, dp);
        return dp[n][amount] = notpick;
    }
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    int ans = solve(coins, n, amount, dp);
    if (ans == INT_MAX - 1 || ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

int coinChangeTabulation(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 1; j < amount + 1; j++)
    {
        dp[0][j] = INT_MAX - 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                int pick = 1 + dp[i][j - coins[i - 1]];
                int notpick = dp[i - 1][j];
                dp[i][j] = min(pick, notpick);
            }
            else
            {
                int notpick = dp[i - 1][j];
                dp[i][j] = notpick;
            }
        }
    }
    if (dp[n][amount] == INT_MAX - 1 || dp[n][amount] == INT_MAX)
        return -1;
    return dp[n][amount];
}