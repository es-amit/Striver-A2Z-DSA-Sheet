#include <bits/stdc++.h>
using namespace std;
int solve(int i, int buy, vector<int> &prices, int &n, vector<vector<int>> &dp)
{
    // buy - true means we can buy the stock
    // false means we can't buy hence can sell only the stoc

    if (i == n)
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(i + 1, 0, prices, n, dp), 0 + solve(i + 1, 1, prices, n, dp));
    }
    else
    {
        profit = max(prices[i] + solve(i + 1, 1, prices, n, dp), 0 + solve(i + 1, 0, prices, n, dp));
    }
    return dp[i][buy] = profit;
}
int maxProfitMemo(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solve(0, 1, prices, n, dp);
}

int maxProfitTabulation(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            }
            else
            {

                profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

int maxProfitSpaceOptimized(vector<int> &prices)
{
    int n = prices.size();
    vector<int> ahead(2, 0);
    vector<int> curr(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int profit = 0;
        // not buy
        curr[0] = max(prices[i] + ahead[1], 0 + ahead[0]);

        // buy
        curr[1] = max(-prices[i] + ahead[0], 0 + ahead[1]);

        ahead[0] = curr[0];
        ahead[1] = curr[1];
    }
    return ahead[1];
}