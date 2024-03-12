#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int buy = prices[0];
    int n = prices.size();
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - buy;
        profit = max(cost, profit);
        buy = min(prices[i], buy);
    }
    return profit;
}