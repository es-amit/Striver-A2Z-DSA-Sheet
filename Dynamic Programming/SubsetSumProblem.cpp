#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (arr[n - 1] <= sum)
    {
        bool pick = solve(arr, n - 1, sum - arr[n - 1], dp);
        bool notpick = solve(arr, n - 1, sum, dp);
        return dp[n][sum] = pick || notpick;
    }
    else
    {
        bool notpick = solve(arr, n - 1, sum, dp);
        return dp[n][sum] = notpick;
    }
}
bool isSubsetSumMemo(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return solve(arr, n, sum, dp);
}


bool isSubsetSumTabulation(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }
    for (int j = 1; j < sum + 1; j++)
    {
        dp[0][j] = false;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                bool pick = dp[i - 1][j - arr[i - 1]];
                bool notpick = dp[i - 1][j];
                dp[i][j] = pick || notpick;
            }
            else
            {
                bool notpick = dp[i - 1][j];
                dp[i][j] = notpick;
            }
        }
    }
    return dp[n][sum];
}