#include <bits/stdc++.h>
using namespace std;
int solve(int i, int buy, int trans, vector<int> &prices, int &n, vector<vector<vector<int>>> &dp)
{
    // buy - true means we can buy the stock
    // false means we can't buy hence can sell only the stoc

    if (i == n || trans == 0)
        return 0;
    if (dp[i][buy][trans] != -1)
        return dp[i][buy][trans];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(i + 1, 0, trans, prices, n, dp), 0 + solve(i + 1, 1, trans, prices, n, dp));
    }
    else
    {
        profit = max(prices[i] + solve(i + 1, 1, trans - 1, prices, n, dp), 0 + solve(i + 1, 0, trans, prices, n, dp));
    }
    return dp[i][buy][trans] = profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, 1, 2, prices, n, dp);
}

int maxProfitTabulation(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + dp[i + 1][0][cap], 0 + dp[i + 1][1][cap]);
                }
                else
                {
                    profit = max(prices[i] + dp[i + 1][1][cap - 1], 0 + dp[i + 1][0][cap]);
                }
                dp[i][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int maxProfitSpaceOptimized(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy == 0)
                { // We can buy the stock
                    cur[buy][cap] =
                        max(0 + ahead[0][cap], -prices[ind] + ahead[1][cap]);
                }

                if (buy == 1)
                { // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap],
                                        prices[ind] + ahead[0][cap - 1]);
                }
            }
        }
        // Update the ahead state with the current state for the next
        // iteration.
        ahead = cur;
    }

    return ahead[0][2];
}