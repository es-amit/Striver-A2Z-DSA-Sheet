#include <bits/stdc++.h>
using namespace std;
void SubsetSum(int arr[], int n, int sum, vector<vector<int>> &dp)
{
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
}
int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    SubsetSum(arr, n, sum, dp);

    int mini = INT_MAX;
    for (int j = 0; j < (sum / 2) + 1; j++)
    {
        if (dp[n][j] == true)
        {
            mini = min(mini, abs(sum - 2 * j));
        }
    }
    return mini;
}