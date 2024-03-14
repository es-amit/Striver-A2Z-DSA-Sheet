#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int cost = (cuts[j + 1] - cuts[i - 1]) + solve(cuts, i, k - 1, dp) + solve(cuts, k + 1, j, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return solve(cuts, 1, c, dp);
}