#include <bits/stdc++.h>
using namespace std;
bool solve(int arr[], int n, int sum, vector<vector<int>> &dp)
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
int equalPartition(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
        return false;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return solve(arr, n, sum / 2, dp);
}