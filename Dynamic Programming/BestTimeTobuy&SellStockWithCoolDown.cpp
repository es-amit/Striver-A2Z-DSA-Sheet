#include <bits/stdc++.h>
using namespace std;
int solve(int i, int buy, vector<int> &prices, int &n, vector<vector<int>> &dp)
{
    // buy - true means we can buy the stock
    // false means we can't buy hence can sell only the stoc

    if (i >= n)
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
        profit = max(prices[i] + solve(i + 2, 1, prices, n, dp), 0 + solve(i + 1, 0, prices, n, dp));
    }
    return dp[i][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solve(0, 1, prices, n, dp);
}