#include <bits/stdc++.h>
using namespace std;
bool solve(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (i == 0)
        return (arr[0] == k);
    if (dp[i][k] != -1)
        return dp[i][k];
    bool pick = false;
    if (arr[i] <= k)
    {
        pick = solve(i - 1, k - arr[i], arr, dp);
    }
    bool notpick = solve(i - 1, k, arr, dp);
    return dp[i][k] = pick || notpick;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}