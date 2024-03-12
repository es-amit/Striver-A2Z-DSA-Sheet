#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int buy, vector<int> &prices, int &fee, int &n, vector<vector<int>> &dp)
{
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit = 0;
    // buy
    if (buy)
    {
        profit = max(-prices[ind] + solve(ind + 1, 0, prices, fee, n, dp), 0 + solve(ind + 1, 1, prices, fee, n, dp));
    }
    else
    {
        profit = max(prices[ind] + solve(ind + 1, 1, prices, fee, n, dp) - fee, 0 + solve(ind + 1, 0, prices, fee, n, dp));
    }
    return dp[ind][buy] = profit;
}
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solve(0, 1, prices, fee, n, dp);
}